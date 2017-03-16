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

typedef unsigned long long ull;

const ull max_gen = 40;
const ull pow_gen = (1ull << 40);

ull pgcd(ull x, ull y) {
	while (y) {
		x %= y;
		swap(x, y);
	}
	return x;
}

ull log2(ull x) {
	ull r = 0;
	while (x > 1) {
		r += 1;
		x /= 2ull;
	}
	return r;
}

int solve(ull p, ull q) {
	ull d = pgcd(p, q);
	ull u = p / d;
	ull v = q / d;
	if (pow_gen % v != 0) {
		return -1;
	} else {
		return log2(v) - log2(u);
	}
}

int main(void) {
	int t; cin >> t;
	forn(nc, t) {
		ull p, q; char c;
		cin >> p >> c >> q;
		int r = solve(p, q);
		if (r < 0) {
			cout << "Case #" << (nc+1) << ": impossible" << endl;
		} else {
			cout << "Case #" << (nc+1) << ": " << r << endl;
		}
	}
	return 0;
}
