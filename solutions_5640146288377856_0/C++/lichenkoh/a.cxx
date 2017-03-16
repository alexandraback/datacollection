#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll r,c,w;
		cin >> r; cin >> c; cin >> w;
		ll ans = c/w;
		ans *= r;
		ans += (w-1);
		if ((w > 1) && (c % w != 0)) {
			ans++;
		}
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
