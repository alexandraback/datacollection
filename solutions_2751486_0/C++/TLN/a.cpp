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

template<typename T> inline void ignore(T) {}

bool vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

mpz_class nvalue(const string &s, int n) {
	mpz_class f = 0;
	mpz_class r = 0;
	int t = 0;
	for(int i = 0; i < (int) s.size(); ++i) {
		t = (vowel(s[i]) ? 0 : t + 1);
		if (t >= n) {
			f += i - n + 2;
			r = i - n + 2;
		} else {
			f += r;
		}
	}
	return f;
}

int main(void) {
	int t; cin >> t;
	forn(nc, t) {
		string s; int n;
		cin >> s >> n;
		mpz_class ans = nvalue(s, n);
		cout << "Case #" << (nc+1) << ": " << ans << endl;
	}
	return 0;
}
