#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
struct XD{
    long long type;
    long long value;
}d1[105],d2[105],left[105][105];
long long dp[105][105],is[105][105];
long long MIN(long long a,long long b){
    if(a > b)return b;
    return a;
}
int main (){
    int T,ca=0;
    int i,j,n,m,k;
    long long tmp,t1,t2;
    scanf("%d",&T);
    while(T--){
        ca++;
        printf("Case #%d:",ca);
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%lld%lld",&d1[i].value,&d1[i].type);
        }
        for(i=1;i<=m;i++){
            scanf("%lld%lld",&d2[i].value,&d2[i].type);
        }
        memset(dp,0,sizeof(dp));
        memset(is,0,sizeof(is));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(dp[i][j] < dp[i][j-1])dp[i][j] = dp[i][j-1];
                if(dp[i][j] < dp[i-1][j])dp[i][j] = dp[i-1][j];
                if(d1[i].type == d2[j].type){
                    tmp = MIN(d1[i].value,d2[j].value);
                    if(dp[i][j] < dp[i-1][j-1] + tmp){
                        dp[i][j] = dp[i-1][j-1]+tmp;

                     //   is[i][j] = 1;
                     //   left[i][j].type = d1[i].type;
                      //  left[i][j].value = d1[i].value + d2[j].value - 2*tmp;
                    }
                }

            }
        }
        printf(" %lld\n",dp[n][m]);
    }
    return 0;
}

/*
4
3 3
10 1 20 2 25 3
10 2 30 3 20 1
*/

