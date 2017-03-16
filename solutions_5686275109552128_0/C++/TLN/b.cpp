/*
 * b.cpp
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

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {}

int solve(const vector<int> &p) {
	int dmax = p.size();
	int pmax = *max_element(p.begin(), p.end());
	vector<vector<int> > cost(dmax, vector<int> (pmax));


	forn (i, dmax) {
		forn (s, pmax) {
			cost[i][s] = numeric_limits<int>::max();
			for (int r = 0; r <= s; ++r) {
				int q = s - r + 1;
				int rem = (p[i] / q) + (p[i] % q == 0 ? 0 : 1);
				int prev = (i == 0 ? 0 : cost[i - 1][r]);
				cost[i][s] = min(cost[i][s], max(prev, rem));
			}
		}
	}

	int best = numeric_limits<int>::max();
	forn (s, pmax) {
		best = min(best, s + cost[dmax - 1][s]);
	}
	return best;
}

int main(void) {
	int t; cin >> t;
	forn (k, t) {
		int d; cin >> d;
		vector<int> p(d);
		forn (i, d) {
			cin >> p[i];
		}
		int ans = solve(p);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}
