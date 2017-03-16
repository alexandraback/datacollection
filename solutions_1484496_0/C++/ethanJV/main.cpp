#include<stdio.h>
#define MAX 2000000

int nums[50];
int set1[50],set2[50];
int dp[25][4000005];

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int main(){
    int T,N;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int s1=0,s2=0;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
            scanf("%d",&nums[j]);
        for(int j=0;j<=4000000;j++)
            dp[N][j]=-1;
        dp[N][MAX]=0;
        for(int j=N-1;j>=0;j--){
            for(int k=-MAX;k<=MAX;k++){
                dp[j][k+MAX]=-1;
                if(dp[j+1][k+MAX]>=0)
                    dp[j][k+MAX]=0;
                if(k+nums[j]+MAX<=MAX)
                    if(dp[j+1][k+nums[j]+MAX]>=0)
                        dp[j][k+MAX]=1;
                if(k-nums[j]+MAX>=0)
                    if(dp[j+1][k-nums[j]+MAX]>=0)
                        dp[j][k+MAX]=2;
            }
        }
        int suma=0;
        for(int j=0;j<N;j++){
            if(dp[j][suma+MAX]==1){
                set1[s1++]=nums[j];
                suma+=nums[j];
            } else if(dp[j][suma+MAX]==2){
                set2[s2++]=nums[j];
                suma-=nums[j];
            }
        }
        printf("Case #%d:\n",i);
        if(s1>0&&s2>0&&suma==0){
            for(int j=0;j<s1;j++){
                if(j>0) printf(" ");
                printf("%d",set1[j]);
            } printf("\n");
            for(int j=0;j<s2;j++){
                if(j>0) printf(" ");
                printf("%d",set2[j]);
            } printf("\n");
        } else printf("Impossible\n");
    }
    return 0;
}
