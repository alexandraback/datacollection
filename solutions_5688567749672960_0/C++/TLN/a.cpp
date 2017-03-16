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

const int N = 10000000;
vector<int> cost;

ull flip(ull x) {
	ull y = 0;
	while (x != 0 && (x % 10) == 0) {
		x /= 10;
	}
	while (x != 0) {
		y = y*10 + (x % 10);
		x /= 10;
	}
	return y;
}

void precomp() {
	cost.assign(N, -1);
	queue<int> q, r;
	cost[0] = 0;
	q.push(0);
	int c = 1;
	while (not q.empty()) {
		int x = q.front(); q.pop();
		int y = x + 1;
		if (y < N && cost[y] == -1) {
			cost[y] = c;
			r.push(y);
		}
		y = flip(x);
		if (y < N && cost[y] == -1) {
			cost[y] = c;
			r.push(y);
		}
		if (q.empty()) {
			swap(q, r);
			++c;
		}
	}
}

int solve(int n) {
	return cost[n];
}

int main(void) {
	int t; cin >> t;
	precomp();
	forn(k, t) {
		int n; cin >> n;
		int ans = solve(n);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}
