#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int cas, T;
    int E,R,N;
    int i,j,k,ni,nj;
    long long nv;
    int v[20];
    long long dp[20][20];
    
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++){
        scanf("%d %d %d", &E,&R,&N);
        for (i=0;i<N;i++) scanf("%d",v+i);
        memset(dp,0,sizeof(dp));
        for (k=0;k<N;k++){
            for (i=0;i<=E;i++){
                for (j=0;j<=i;j++){
                    // k+1, i-j+R
                    nv = dp[k][i] + v[k]*j;
                    ni = i-j+R;
                    if (ni>E) ni=E;
//                    printf("%d %d %lld\n", k+1,ni,nv);
                    if (dp[k+1][ni] < nv) dp[k+1][ni]=nv;
                }
            }
        }
        nv = 0;
        for (i=0;i<=E;i++) if (dp[N][i]>nv) nv=dp[N][i];
        printf("Case #%d: %lld\n", cas, nv);
    }
    return 0;
}

