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

struct Kuhn {
	int n, k;
	vector < vector<int> > g;
	vector<int> mt;
	vector<char> used;
	 
	bool try_kuhn (int v) {
		if (used[v])  return false;
		used[v] = true;
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (mt[to] == -1 || try_kuhn (mt[to])) {
				mt[to] = v;
				return true;
			}
		}
		return false;
	}

	int result;
	 
	Kuhn(int n, int k, vector<vector<int>> g):n(n), k(k), g(g) {
		result = 0;
		mt.assign (k, -1);
		for (int v=0; v<n; ++v) {
			used.assign (n, false);
			try_kuhn (v);
		}

		for (int i=0; i<k; ++i)
			if (mt[i] != -1)
				result++;
	}
};

int solve() {
	next(int, n);

	auto ps = readVector<pair<string, string>>(n);
	map<string, int> m1;
	map<string, int> m2;
	vector<pair<int, int>> psi;
	
	int c1 = 0;
	int c2 = 0;
	for (auto &p : ps) {
		if (!m1.count(p.first)) m1[p.first] = c1++;
		if (!m2.count(p.second)) m2[p.second] = c2++;

		psi.push_back({m1[p.first] , m2[p.second]});
	}

	vector<vector<int>> g(m1.size());
	for (auto &p : psi) {
		g[p.first].push_back(p.second);
	}

	Kuhn kuhn(m1.size(), m2.size(), g);

	return n - (m1.size() + m2.size() - kuhn.result);
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