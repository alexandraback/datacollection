#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using std::min;
using std::max;
int dp[20][20];

void solve(){
    int E, R, N;
    scanf("%d%d%d", &E, &R, &N);
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<=N;++i)
        for(int j=0;j<=E;++j)
            dp[i][j]=-100000000;
    dp[0][E] = 0;
    for(int i=1;i<=N;++i){
        int v;
        scanf("%d", &v);
        for(int j=0; j<=E;++j){
            for(int k=0;k<=j;++k){
                int t = min(j-k+R, E);
                dp[i][t] = max(dp[i][t], dp[i-1][j] + k * v);
                //if(dp[i][t]>0)
                //printf("(%d, %d) ---- %d * %d ---> (%d, %d)\n", i-1,j, k,v, i, t);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=E;++i)
        ans = max(ans, dp[N][i]);
    printf("%d\n", ans);
    return;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t){
        printf("Case #%d: ", t);
        solve();
    }
}