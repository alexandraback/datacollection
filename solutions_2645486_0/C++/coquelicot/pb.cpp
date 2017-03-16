#include <cstdio>

int val[10010];
long long dp[10000010];
long long bst[10000010];

int main(){

    int t;
    scanf("%d" ,&t);

    for(int T = 1; T <= t; T++){

        int N, E, R;
        scanf("%d %d %d" ,&E ,&R ,&N);
        if(R > E) R = E;

        for(int i = 1; i <= N; i++) scanf("%d" ,&val[i]);
        for(int j = 0; j <= E; j++) dp[j] = 0;

        for(int i = 1; i <= N; i++){

            int obj = E;
            for(int j = E - 1; j >= 0; j--){
                if(dp[j] - dp[obj] > 1LL * (obj - j) * val[i]) obj = j;
                bst[j] = dp[obj] + 1LL * (obj - j) * val[i];
            }
            for(int j = 0; j <= E - R; j++) dp[j + R] = bst[j];

        }

        printf("Case #%d: %lld\n" ,T ,dp[R]);

    }

}
