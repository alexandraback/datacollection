#include <bits/stdc++.h>

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define REP(i, a, b) for(int i = (a); i < int(b); ++i)
#define rep(i, n) REP(i, 0, n)
#define ALL(x) begin(x), end(x)

template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

int table[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0},
};

bool negative[4][4] = {
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1},
};

bool solve() {
	int L, X;
	string s;
	cin >> L >> X >> s;

	vector<int> vec;
	vec.reserve(L);

	for(const auto &c : s) {
		vec.emplace_back(c - 'i' + 1);
	}

	int pos = 0;
	int num = 0;

	for(int to = 1; to <= 3; ++to) {
		int v = 0;
		bool plus = true;

		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < L; ++j) {
				if(negative[v][vec[pos]]) plus = !plus;
				v = table[v][vec[pos]];

				++pos;
				if(pos >= L) {
					pos = 0;
					++num;
				}

				if(v == to && plus) goto ok;
			}
		}

		return false;
	ok:;
	}

	if(pos == 0) pos = L;
	if(num > X || (num == X && pos < L)) return false;

	int v = 0;
	bool plus = true;

	if(pos < L) ++num;
	for(; pos < L; ++pos) {
		if(negative[v][vec[pos]]) plus = !plus;
		v = table[v][vec[pos]];
	}

	const int rest_num = X - num;
	int loop = rest_num % 8;
	while(loop--) {
		for(int i = 0; i < L; ++i) {
			if(negative[v][vec[i]]) plus = !plus;
			v = table[v][vec[i]];
		}
	}

	return v == 0 && plus;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		const auto ans = solve() ? "YES" : "NO";
		cout << "Case #" << t << ": " << ans << "\n";
	}

	return EXIT_SUCCESS;
}
