#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define PB push_back
#define MP make_pair
typedef long long ll;

ll r, t;
ll score(ll mid) {
	if (2.0 * r * mid + (double)2*mid * mid - mid > 2e18)
		return t+1;
	return 2 * r * mid + 2*mid*mid-mid;
}
int main() {
	int test;
	cin >> test;
	for (int cas = 1; cas <= test; ++cas) {
		cin >> r >> t;
		ll l = 1, r = 1ll << 31;
		while (l <= r) {
			ll mid = (l + r) / 2;
			if (score(mid) <= t)
				l = mid + 1;
			else
				r = mid - 1;
		}
		printf("Case #%d: ",cas);
		cout << l-1 << endl;
	}
}

