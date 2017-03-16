#include <bits/stdc++.h>

using namespace std;

long long odwroc(int w) {
    long long ret = 0;
    while(w >= 1) {
        ret *= 10;
        ret += w % 10;
        w /= 10;
    }
    return ret;
}

long long n; 
int t;
int dp[1000005];

int main() {
    scanf("%d", &t);
    for(int test = 1; test <= t; test++) {
        printf("Case #%d: ", test);
        scanf("%lld", &n);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(odwroc(i) >= i || i % 10 == 0) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = min(dp[i - 1] + 1, dp[odwroc(i) - 1] + 2);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}