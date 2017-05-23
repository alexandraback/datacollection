#include<cstdio>

unsigned long long dp[2][10000001];

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

int main(){
    int testcase;
    int a,i,j,k;
    int maxEnergy;
    int regain;
    int actCount;
    int act[1000];
    int temp;
    unsigned long long max;

    scanf("%d",&testcase);
    for(a=1;a<=testcase;a++){
            scanf("%d %d %d",&maxEnergy,&regain,&actCount);
            for(i=0;i<actCount;i++){
                    scanf("%d",&act[i]);
            }
            for(i=0;i<actCount;i++){
                    if(i==0){
                            for(j=0;j<=maxEnergy;j++){
                                    dp[i][j] = act[i] * (maxEnergy-j);
                            }
                    }else{
                            for(j=0;j<=maxEnergy;j++){
                                    dp[i%2][j] = 0;
                                    for(k=j;k<=maxEnergy;k++){
                                            dp[i%2][j] = Max(dp[i%2][j],act[i] * (k-j) + dp[(i+1)%2][k]);
                                    }
                            }
                    }
                    for(j=1;j<=regain;j++){
                            if(maxEnergy-j < 0) break;
                            dp[i%2][maxEnergy] = Max(dp[i%2][maxEnergy],dp[i%2][maxEnergy-j]);
                    }
                    temp = maxEnergy-1;
                    for(j=maxEnergy-j;j>=0;j--){
                            dp[i%2][temp] = dp[i%2][j];
                            temp--;
                    }
                    while(temp>=0){
                            dp[i%2][temp] = 0;
                            temp--;
                    }
                    /*for(j=0;j<=maxEnergy;j++){
                            printf("%llu ",dp[i%2][j]);
                    }
                    printf("\n");*/
            }
            i--;
            max = 0;
            for(j=0;j<=maxEnergy;j++){
                    max = Max(max,dp[i%2][j]);
            }
            printf("Case #%d: %llu\n",a,max);

    }
    return 0;
}
