#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <set>
#include <assert.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n;
		cin >> n;
		ll *a = new ll[n+1];
		string s;
		cin >> s;
		for (ll i = 0; i <= n; i++) {
			a[i] = s[i]-'0';
		}
		ll ans = 0;
		ll sum = 0;
		for (ll k = 0; k <= n; k++) {
			if (k > sum) {
				ans += (k-sum);
				sum += (k-sum);
			}
			sum += a[k];
			//cout << k << ":" << sum << ":" << ans << endl;
		}
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}