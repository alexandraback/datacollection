#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define INF 999999999999999LL
int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n; cin >> n;
		vector<pair<ll,ll> > h;
		for (ll i = 0; i < n; i++) {
			ll d; ll k; ll m; cin >> d; cin >> k; cin >> m;
			for (ll j = m; j < m+k; j++) {
				h.push_back(MP(j,d));
			}
		}
		sort(h.begin(),h.end());
		ll ans = 0;
		if (h.size() == 2) {
			ll di = h[0].second - 360; ll mi = h[0].first;
			ll dk = h[1].second; ll mk = h[1].first;
			ll lhs = (dk-di)*mi;
			ll rhs = (360-dk)*(mk-mi);
			if (lhs <= rhs) {
				ans = 1;
			}
		}
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
