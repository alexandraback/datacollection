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

string make_back(string s, LL x) {
	int n = s.size();
	FOR (i, 0, n) {
		s[n - 1 - i] = '0' + x % 10;
		x /= 10;
	}
	return s;
}

LL to_num(string s) {
	LL res = 0;
	for (auto c : s) assert(c != '?');
	for (auto c : s) res = res * 10 + c - '0';
	return res;
}

pair<string, string> solve() {
	next(string, s1);
	next(string, s2);

	auto res = make_pair(LongMaxVal, make_pair(0LL, 0LL));

	FOR (i, 0, s1.size() + 1) {
		if (i == s1.size()) {
			auto num1 = to_num(s1);
			auto num2 = to_num(s2);

			minimize(res, { abs(num1 - num2) , {num1, num2}});
			break;
		}

		bool q1 = s1[i] == '?';
		bool q2 = s2[i] == '?';

		FOR (d1, 0, 10) FOR (d2, 0, 10) {
			if (q1 || d1 + '0' == s1[i])
			if (q2 || d2 + '0' == s2[i])
			if (d1 != d2) {
				string r1 = s1;
				string r2 = s2;

				r1[i] = '0' + d1;
				r2[i] = '0' + d2;

				FOR (j, i + 1, r1.size()) {
					if (r1[j] == '?') r1[j] = d1 > d2 ? '0' : '9';
					if (r2[j] == '?') r2[j] = d2 > d1 ? '0' : '9';
				}

				auto num1 = to_num(r1);
				auto num2 = to_num(r2);

				minimize(res, { abs(num1 - num2) , {num1, num2}});
			}
		}

		if (s1[i] == '?' && s2[i] == '?') {
			s1[i] = s2[i] = '0';
		} else if (s1[i] == '?') {
			s1[i] = s2[i];
		} else if (s2[i] == '?') {
			s2[i] = s1[i];
		} else if (s1[i] != s2[i]) break;
	}

	assert(res.first < LongMaxVal);

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