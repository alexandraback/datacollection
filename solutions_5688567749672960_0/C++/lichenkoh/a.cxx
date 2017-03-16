#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define INF 9999999999999LL
ll reverse(ll x) {
	ll y = 0;
	while(x > 0) {
		y *= 10;
		y += (x % 10);
		x /= 10;
	}
	return y;
}

int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n; cin >> n;
		ll *dp = new ll[n+1];
		for (ll i = 0; i <= n; i++) {
			dp[i] = INF;
		}
		dp[1] = 1;
		for (ll x = 1; x < n; x++) {
			dp[x+1] = min(dp[x+1],dp[x] + 1);
			ll rx = reverse(x);
			if (1 <= rx && rx <= n) {
				dp[rx] = min(dp[rx], dp[x] + 1);
			}
		}
		ll ans = dp[n];
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
