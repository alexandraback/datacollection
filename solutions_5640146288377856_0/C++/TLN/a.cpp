/*
 * a.cpp
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

int numOfOnes(int x) {
	int z = 0;
	while (x) {
		z += (x & 1);
		x >>= 1;
	}
	return z;
}

int largestShip(int x, int c) {
	int w    = 0;
	int wmax = 0;
	forn(i, c) {
		if (x & 1) {
			wmax = max(w, wmax);
			w    = 0;
		} else {
			++w;
		}
		x >>= 1;
	}
	return max(wmax, w);
}

int solve(int r, int c, int w) {
	int ans = r * (c / w) + w;
	if (c % w == 0) {
		return ans - 1;
	} else {
		return ans;
	}
	/*int xmax = (1 << c) - 1;
	int nmin = c;
	forn(x, xmax) {
		cout << x << ": " << largestShip(x, c) << " " << numOfOnes(x) << endl;
		if (largestShip(x, c) < w) {
			nmin = min(nmin, numOfOnes(x));
		}
	}*/
	//return ans;
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		int r, c, w;
		cin >> r >> c >> w;
		int ans = solve(r, c, w);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}
