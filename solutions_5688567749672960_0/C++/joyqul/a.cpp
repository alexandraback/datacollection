#include <bits/stdc++.h>

using namespace std;

long long input;

long long dp[1000001];

long long rev(long long now) {
    long long ans = 0;
    long long target = now;
    while (target > 0) {
        ans = ans*10 + target%10;
        target /= 10;
    }
    return ans;
}

long long solve(long long now) {
    if (dp[now] != 0) return dp[now];
    if (now < 10) return dp[now] = now;
    long long reverse_now = rev(now);
    if (reverse_now >= now || now%10 == 0) {
        return dp[now] = 1+solve(now-1);
    }
    return dp[now] = 1+min(solve(now-1), solve(reverse_now));
}

int main () {
    int tcase;
    scanf("%d", &tcase);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= tcase; ++i) {
        
        cin >> input;
        printf("Case #%d: ", i);
        cout << solve(input) << endl;
    }
    return 0;
}
