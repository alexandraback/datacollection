#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

typedef long long ll;
int t;
ll n;
ll dp[N];

ll res(ll x) {
    ll ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

ll dfs(ll n) {
    if (dp[n] != -1) return dp[n];
    if (n == 1) return dp[n] = 1;
    dp[n] = 100000000;
    ll tmp = res(n);
    if (res(tmp) == n && tmp < n) dp[n] = min(dp[n], dfs(tmp) + 1);
    dp[n] = min(dp[n], dfs(n - 1) + 1);
    return dp[n];
}

int main() {
    for (int i = 0; i < N; i++) dp[i] = -1;
    int cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("Case #%d: %lld\n", ++cas, dfs(n));
    }
    return 0;
}
