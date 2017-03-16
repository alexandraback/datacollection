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

bool divides_it(LL mask, int base, int div) {
	int rem = 0;
	int mult = 1;
	while (mask) {
		if (mask & 1) rem += mult;
		mult = mult * base % div;
		mask /= 2;
	}

	return rem % div == 0;
}

bool find_div(LL mask, int base, vector<int> &divs) {
	divs[base - 2] = -1;
	FOR (d, 2, 30) if (divides_it(mask, base, d)) {
		divs[base - 2] = d;
		return true;
	}

	return false;
}

vector<pair<string, vector<int>>> solve() {
	next(int, n);
	next(int, j);

	LL from = (1LL << (n - 1)) + 1;
	LL to = (1LL << n) - 1;

	vector<pair<string, vector<int>>> result;
	for (LL mask = from ; mask <= to ; mask += 2) {
		if (result.size() == j) break;

		static vector<int> divs(9, -1);
		FOR (b, 2, 11) {
			if (!find_div(mask, b, divs)) break;
		}

		bool ok = true;
		for (auto d : divs) if (d == -1) ok = false;
		if (!ok) continue;

		string s = "";
		LL tmp = mask;
		while (tmp) {
			s.push_back(tmp & 1 ? '1' : '0');
			tmp /= 2;
		}
		reverse(all(s));
		result.push_back({s , divs});
	}

	assert(result.size() == j);
	return result;
}

int main() {
	srand (time(NULL));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fixed(cout); cout << setprecision(10);
	
	next(int, t);
	FOR (i, 1, t + 1) {
		cout << "Case #" << i << ": " << endl;
		for (auto &p : solve()) cout << p;
		// cout << endl;
	}
}