#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

ll p10[16];
const ll INF = 1ll << 55;

const int MAXN = 1111111;
ll dp[MAXN];

ll rev(ll N) {
    ll ret = 0;
    while (N) {
        ret = 10*ret + N%10;
        N /= 10;
    }
    return ret;
}

ll solve(ll N) {
    for (int i = 0; i < MAXN; i++) dp[i] = INF;
    dp[N] = 1;
    for (ll i = N-1; i >= 1; i--) {
        ll tmp = rev(i);
        if (tmp > N) dp[i] = dp[i+1]+1;
        else dp[i] = min(dp[i+1], dp[tmp]) + 1;
    }
    return dp[1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    p10[0] = 1;
    for (int i = 0 ;i < 16; i++) p10[i] *= 10;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll N;
        cin >> N;
        printf("Case #%d: %lld\n", t, solve(N));
    }
    return 0;
}
