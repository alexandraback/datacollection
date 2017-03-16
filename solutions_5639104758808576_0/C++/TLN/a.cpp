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

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {}

int solve(const string &s) {
	int sum = 0;
	int gap = 0;
	forn (i, (int) s.size()) {
		if (s[i] != '0') {
			int si = s[i] - '0';
			gap = max(gap, i - sum);
			sum += si;
		}
	}
	return gap;
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = solve(s);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}
