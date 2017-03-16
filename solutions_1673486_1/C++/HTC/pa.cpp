#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
double dp[1000005];
double p[1000005];
int main (){
    int T,ca=0;
    int a,B,i,j;
    double ans = 1e10,tmp;
    scanf("%d",&T);
    while(T--){
        ca++;
        printf("Case #%d:",ca);
        scanf("%d%d",&a,&B);
        ans = B+2;
        dp[0] = 1;
        for(i=1;i<=a;i++){
            scanf("%lf",&p[i]);
            if(i == 1)dp[i] = p[i];
            else dp[i] = p[i] * dp[i-1];
        }

        for(j=0;j<=a;j++){
            tmp = dp[a-j] * (B-(a-j)+j+1) + (1-dp[a-j]) * (B-(a-j)+j+1 + B+1);
            if(tmp < ans)ans = tmp;
            //printf("j %d tmp %lf\n",j,tmp);
        }

        printf(" %lf\n",ans);
    }
    return 0;
}
/*
3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1
*/
