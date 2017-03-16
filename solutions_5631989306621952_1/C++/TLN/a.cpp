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

string solve(const string s) {
	int n = (int) s.size();
	string cur(1, s[0]);
	for (int i = 1; i < n; ++i) {
		string c(1, s[i]);
		string pre = c + cur;
		string pos = cur + c;
		if (pre < pos) {
			cur = pos;
		} else {
			cur = pre;
		}
	}
	return cur;
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		string s; cin >> s;
		string ans = solve(s);
		cout << "Case #" << (k+1) << ": " << ans << endl;
	}
	return 0;
}
