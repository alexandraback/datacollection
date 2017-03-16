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

constexpr int MAX = 1000;
int memo[MAX + 1][MAX + 1];

int rec(int pancake, int num_eat) {
	auto &res = memo[pancake][num_eat];
	if(res != -1) return res;

	if(pancake <= num_eat) {
		res = 0;
	}
	else {
		res = INT_MAX;
		for(int i = 1; i <= pancake / 2; ++i) {
			chmin(res, rec(i, num_eat) + rec(pancake - i, num_eat) + 1);
		}
	}
	return res;
}

int calc(const vector<int> &P, int num_eat) {
	int res = num_eat;
	for(const auto &pancake : P) {
		res += rec(pancake, num_eat);
	}
	return res;
}

string solve() {
	int D;
	cin >> D;

	vector<int> P(D);
	for(auto &e : P) cin >> e;

	sort(begin(P), end(P));

	int res = INT_MAX;
	for(int i = 1; i <= 1000; ++i) {
		chmin(res, calc(P, i));
	}
	return to_string(res);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	memset(memo, -1, sizeof(memo));

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": " << solve() << "\n";
	}

	return EXIT_SUCCESS;
}
