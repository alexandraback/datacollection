
#include <cstdio>
#include <cstring>

int dp[20][20] ;
int can[10] ;

int maxv(int i1, int i2){
    return i1 > i2 ? i1 : i2 ;
}

int main(){
    int T, E, R, N ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        scanf("%d%d%d", &E, &R, &N) ;
        if(R > E)   R = E ;
        memset(dp, -1, sizeof(dp)) ;
        dp[0][E-R] = 0 ;
        for(int i = 1 ; i <= N ; i++){
            int vi ;
            scanf("%d", &vi) ;
            for(int j = R ; j <= E ; j++){
                for(int k = 0 ; k <= j ; k++){
                    dp[i][j-k] = maxv(dp[i][j-k], dp[i-1][j-R]+k*vi) ;
                }
            }
        }
        printf("Case #%d: ", time) ;
        printf("%d\n", dp[N][0]) ;
    }
    return 0 ;
}
