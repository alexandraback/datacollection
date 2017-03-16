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
#include <cassert>
#include <gmpxx.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {
}

bool compat(int i, const string &s) {
	for (char c : s) {
		if (c == '?') { i /= 10; continue; }
		int x = c - '0';
		if (i % 10 != x) { return false; }
		i = i / 10;
	}
	return true;
}

void write(int i, string &s) {
	for (char &c : s) {
		c = (i % 10) + '0';
		i /= 10;
	}
}

struct score {
	int i, j;
	score(int _i, int _j) : i(_i), j(_j) {}

	bool is_best(const score &o) {
		int d = std::abs(i - j);
		int od = std::abs(o.i - o.j);
		return (d < od || (d == od &&
			(i < o.i || (i == o.i &&
				(j < o.j)))));
	}
};

pair<string, string> solve(string a, string b) {
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	int n = 1;
	for(auto x : a) {
		(void) x;
		n *= 10;
	}

	score best(n, 0);
	forn(i, n) {
		if (compat(i, a)) {
			forn(j, n) {
				if (compat(j, b)) {
					score sc(i, j);
					if (sc.is_best(best)) {
						best = sc;
					}
				}
			}
		}
	}

	write(best.i, a);
	write(best.j, b);
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	return make_pair(a, b);
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		string a, b; cin >> a >> b;
		auto ans = solve(a, b);
		string l = ans.first, r = ans.second;
		cout << "Case #" << (k+1) << ": " << l << " " << r << endl;
	}
	return 0;
}
