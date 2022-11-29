#include <stdio.h>
#include <stdlib.h>


struct coordinate_value{
    int  MaxValue, MinValue;
};

void print_image_array(int* Array){
    // 전달 받은 이미지 배열 출력
    int (*TooDimensionalAarry)[15] = (int(*)[15]) Array;
    printf("\n=================================\n");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            printf("%d ", TooDimensionalAarry[i][j]);
        }
        printf("\n");
    }

}

int compare(const void *a, const void *b) 
{ 
    return ((int*)a - (int*)b);

}

struct coordinate_value print_roi_iamge_array_or_set_value(int* Array, int ArraySize, int* StartX, int* StartY, int* EndX, int* EndY){
    // 전달 받은 좌표값으로 타겟 roi 배열 출력
    int StartValue, EndValue, TmpVlaue;
    int TmpIndex = 0;
    int* OneDimensionalAarry = (int*)malloc(sizeof(ArraySize));
    int (*TooDimensionalAarry)[15] = (int(*)[15]) Array;
    struct coordinate_value ToTalCoordinateValue;

    printf("\n=================================\n");
    for (int i = *StartY; i <= *EndY; i++){
        for (int j = *StartX; j <= *EndX; j++){
            printf("%d ",TooDimensionalAarry[i][j]);
        }
        printf("\n");
    }

    for (int i = *StartY; i <= *EndY; i++){
        for (int j = *StartX; j <= *EndX; j++){
            OneDimensionalAarry[TmpIndex] = TooDimensionalAarry[i][j];
            TmpIndex++;
        }
        TmpIndex++;
    }

    //qsort(OneDimensionalAarry, sizeof(OneDimensionalAarry)/sizeof(int), 4, compare);
    //코드 정렬 필요함

    ToTalCoordinateValue.MinValue = OneDimensionalAarry[0];
    ToTalCoordinateValue.MaxValue = OneDimensionalAarry[sizeof(*OneDimensionalAarry)/sizeof(int)];

   return ToTalCoordinateValue;
}

void total_minimum_or_maxmum_value(int min, int max){
    printf("Min: %d, Max: %d\n", min, max);
}

void total_standard_deviation(){
    //ROI 계산식 추가
}


int main(){
    int StartX, StartY, EndX, EndY;
    int StartValue, EndValue;
    struct coordinate_value CoordinateValues;
    int ImgArray[] = {
        
    };

    while (1){
        printf("시작점의 좌표를 입력해주세요. (ex: 1 1):");
        scanf("%d %d", &StartX, &StartY);
        printf("끝나는점의 좌표를 입력해주세요. (ex: 10 10):");
        scanf("%d %d", &EndX, &EndY);
        if (StartX < 16 && EndX < 16 && EndY < 16 && StartY < 16) break;
    }
    // inupt값 변환 로직 추가 
    print_image_array(ImgArray);
    CoordinateValues = print_roi_iamge_array_or_set_value(ImgArray, sizeof(ImgArray), &StartX, &StartY, &EndX, &EndY);

    total_minimum_or_maxmum_value(CoordinateValues.MaxValue, CoordinateValues.MinValue);

    return 0;
}