#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <set>
#include <assert.h>
using namespace std;
typedef long long ll;
#define INF 922337203685477580
int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n;
		cin >> n;
		ll *a = new ll[n];
		ll maxp = 0;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			maxp = max(maxp,a[i]);
		}
		ll **need = new ll*[n];
		for (ll i = 0; i < n; i++) {
			need[i] = new ll[maxp+1];
			for (ll lim = 1; lim <= maxp; lim++) {
				need[i][lim] = INF;
			}
			for (ll k = 1; k <= maxp; k++) {
				ll get = ((a[i]+k-1)/k);
				need[i][get] = min(need[i][get], k);
			}
			ll minsofar = INF;
			for (ll k = 1; k <= maxp; k++) {
				minsofar = min(minsofar, need[i][k]);
				need[i][k] = minsofar;
			}
		}
		ll ans = maxp;
		for (ll lim = 1; lim <= maxp; lim++) {
			ll add = 0;
			for (ll i = 0; i < n; i++) {
				add += (need[i][lim]-1);
			}
			ans = min(ans,add+lim);
		}
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}