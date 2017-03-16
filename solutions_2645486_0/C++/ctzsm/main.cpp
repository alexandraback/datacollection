/*A*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <iostream>
#include <set>

using namespace std;

int T, nCase = 0;
int E, R, N;
int v[10005], sv[10005] = {0};
long long dp[11][11];
long long solve(){
    cin >> E >> R >> N;
    int m;
    for(int i = 1; i <= N; ++i) cin >> v[i];
    for(int i = 1; i <= N; ++i) sv[i] = sv[i - 1] + v[i];
    for(int i = 1; i <= N; ++i){
        m = max(m, v[i]);
    }
    if(E <= R)
        return (long long)sv[N] * min(E, R);
    memset(dp, -1, sizeof(dp));
    dp[0][E] = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= E; ++j){
            if(dp[i - 1][j] == -1) continue;
            for(int k = 0; k <= j && k + R <= E; ++k){
                dp[i][k + R] = max(dp[i][k + R], dp[i-1][j] + v[i] * (j - k));
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i <= E; ++i) ans = max(ans, dp[N][i]);
    return ans;
}
int main(int argc, char** argv) {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    cin >> T;
    while(nCase < T){
        printf("Case #%d: %lld\n", ++nCase, solve());
    }
    return 0;
}
