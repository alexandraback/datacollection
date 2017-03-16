#include <cstdio>

int dp[110][110];

int main(){

    int t;
    scanf("%d" ,&t);

    for(int T = 1; T <= t; T++){
        
        int n, s, p;
        scanf("%d %d %d" ,&n ,&s ,&p);
        
        for(int i = 1; i <= n; i++){
            
            int score;
            scanf("%d" ,&score);

            int base = score / 3;
            int mxgiv = score == 0? 0: (score + 4) / 3;
            if(mxgiv > 10) mxgiv = 10;
            int cmxgiv = mxgiv > p - 1? p - 1: mxgiv;
            if(cmxgiv < 0) cmxgiv = 0;

            bool a_ns = (base + ((score % 3)? 1: 0)) >= p;
            bool a_s = mxgiv >= p && mxgiv - (score - mxgiv - 1) / 2 > 1;
            bool na_ns = (base + ((score % 3)? 1: 0)) < p;
            bool na_s = cmxgiv - (score - cmxgiv - 1) / 2 > 1;

            for(int j = 0; j <= i && j <= s; j++) dp[i][j] = -200;

            for(int j = 0; j < i && j <= s; j++){

                if(a_ns && dp[i][j] < dp[i - 1][j] + 1){
                    dp[i][j] = dp[i - 1][j] + 1;
                }

                if(a_s && dp[i][j + 1] < dp[i - 1][j] + 1){
                    dp[i][j + 1] = dp[i - 1][j] + 1;
                }

                if(na_ns && dp[i][j] < dp[i - 1][j]){
                    dp[i][j] = dp[i - 1][j];
                }

                if(na_s && dp[i][j + 1] < dp[i - 1][j]){
                    dp[i][j + 1] = dp[i - 1][j];
                }

            }

        }

        printf("Case #%d: %d\n" ,T ,dp[n][s] > 0? dp[n][s]: 0);

    }
}
