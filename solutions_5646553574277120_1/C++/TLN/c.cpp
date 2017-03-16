/*
 * c.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <gmpxx.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {
}

typedef long long ll;

int sub(ll c, ll v, ll &maxRange) {
	int r = 0;
	while (maxRange < v) {
		++r;
		//cout << "adding " << maxRange << endl;
		maxRange += c * maxRange;
	}
	return r;
}

int solve(const vector<ll> &coins, ll c) {
	int d = coins.size();
	int ans = 0;
	ll maxRange = 1;
	forn(i, d) {
		ans += sub(c, coins[i], maxRange);
		maxRange += c*coins[i];
	}
	return ans;
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		int c, d, v;
		cin >> c >> d >> v;
		vector<ll> coins(d + 1);
		forn(i, d) {
			cin >> coins[i];
		}
		coins[d] = v + 1;
 		int ans = solve(coins, c);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}
