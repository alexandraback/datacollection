#include <stdio.h>

int n;
double Final;
double Judge_Score[1000];
double XScore;
double Sum_Of_JS;

int main(){
    int test,i,j,k;
    scanf("%d",&test);
    for(j=1;j<=test;j++){
        scanf("%d",&n);
        Sum_Of_JS=0;
        for(i=0;i<n;i++){
            scanf("%lf",&Judge_Score[i]);
            Sum_Of_JS+=Judge_Score[i];
        }
        Final=Sum_Of_JS*2/n;
        k=0;XScore=0;
        for(i=0;i<n;i++){
            if(Judge_Score[i]>=Final){
                k++;
                XScore+=(Final-Judge_Score[i])/Sum_Of_JS*100;
                Judge_Score[i]=-1;
            }
        }
        XScore/=n-k;
        //printf("Sum: %lf\n",Sum_Of_JS);
        printf("Case #%d: ",j);
        if(n==1){
            printf("0.000\n");continue;
        }
        for(i=0;i<n;i++){
            printf("%lf ",Judge_Score[i]==-1?0:((Final-Judge_Score[i])/Sum_Of_JS*100)+XScore);
        }
        putchar(10);
    }
    return 0;
}
