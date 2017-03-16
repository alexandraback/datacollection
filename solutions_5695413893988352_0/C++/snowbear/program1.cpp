#include "assert.h"
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;

#if LOCAL
	#define DO_NOT_SEND
#endif

typedef long long LL;

int IntMaxVal = (int) 1e20;
int IntMinVal = (int) -1e20;
LL LongMaxVal = (LL) 1e20;
LL LongMinVal = (LL) -1e20;

#define FOR(i, a, b) for(int i = a; i < b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)

template<typename T> inline void minimize(T &a, T b) { a = std::min(a, b); }
template<typename T> inline void maximize(T &a, T b) { a = std::max(a, b); }

template<typename T> inline void swap(pair<T, T> &p) { swap(p.first , p.second ); }

#define all(v) v.begin(),v.end()

#define endl '\n'
template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
#define next(t, i) argument_type<void(t)>::type i; cin >> i;

template <typename T1, typename T2> istream& operator >>(istream& is, pair<T1, T2>& s) { is >> s.first >> s.second; return is; }
template <typename T> ostream& operator << (ostream& os, const vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) { if (i) os << ' '; os << v[i]; } os << endl; return os; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const vector<pair<T1, T2>> &v) { for (int i = 0 ; i < v.size() ; i++) { os << v[i] << endl; } return os; }
template <typename T1, typename T2> ostream& operator <<(ostream& s, const pair<T1, T2>& t) { s << t.first << ' ' << t.second; return s; }
template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

vector<LL> get_matches(string p) {
	vector<LL> res;
	int n = p.size();
	FOR (x, 0, 1000) {
		auto tmp = x;
		bool ok = true;
		FOR (i, 0, p.size()) {
			if (p[n - 1 - i] == '?' || p[n - 1 - i] == '0' + tmp % 10) ;
			else ok = false;
			tmp /= 10;
		}
		ok = ok && tmp == 0;
		if (ok) res.push_back(x);
	}
	return res;
}

string make_back(string s, LL x) {
	int n = s.size();
	FOR (i, 0, n) {
		s[n - 1 - i] = '0' + x % 10;
		x /= 10;
	}
	return s;
}

pair<string, string> solve() {
	next(string, s1);
	next(string, s2);

	auto res = make_pair(LongMaxVal, make_pair(0LL, 0LL));

	auto f1 = get_matches(s1);
	auto f2 = get_matches(s2);

	for (auto x1 : f1) for (auto x2 : f2) minimize(res, { abs(x1 - x2) , { x1 , x2 }});

	return { make_back(s1, res.second.first) , make_back(s2 , res.second.second) };
}

int main() {
	srand (time(NULL));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fixed(cout); cout << setprecision(10);
	
	next(int, t);
	FOR (i, 1, t + 1) {
		auto sol = solve();
		cout << "Case #" << i << ": ";
		cout << sol;
		cout << endl;
	}
}