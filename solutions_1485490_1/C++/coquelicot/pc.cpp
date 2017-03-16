#include <cstdio>

long long dp[110][110];
long long na[110], nb[110];
int ta[110], pta[110], reca[110];
int tb[110], ptb[110], recb[110];

inline long long max(long long a, long long b){
    return (a > b)? a: b;
}
inline long long min(long long a, long long b){
    return (a < b)? a: b;
}

int main(){
    int t;
    scanf("%d" ,&t);
    for(int T = 1; T <= t; T++){
        int n, m;
        scanf("%d %d" ,&n ,&m);
        for(int i = 1; i <= 100; i++){
            reca[i] = recb[i] = 0;
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 0;
            scanf("%lld %d" ,&na[i] ,&ta[i]);
            pta[i] = reca[ta[i]];
            reca[ta[i]] = i;
        }
        for(int i = 1; i <= m; i++){
            dp[0][i] = 0;
            scanf("%lld %d" ,&nb[i] ,&tb[i]);
            ptb[i] = recb[tb[i]];
            recb[tb[i]] = i;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(ta[i] == tb[j]){
                    dp[i][j] = 0;
                    long long lim = 0;
                    for(int l = i; l != 0; l = pta[l]){
                        lim += na[l];
                        long long sum = 0;
                        for(int k = j; k != 0 && sum < lim; k = ptb[k]){
                            sum += min(lim - sum, nb[k]);
                            if(dp[l - 1][k - 1] + sum > dp[i][j]){
                                dp[i][j] = dp[l - 1][k - 1] + sum;
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: %lld\n" ,T ,dp[n][m]);
    }
}
