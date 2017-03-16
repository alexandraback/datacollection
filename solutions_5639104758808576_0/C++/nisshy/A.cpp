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

string solve() {
	int Smax;
	string S;
	cin >> Smax >> S;

	int num = 0;
	int ans = 0;
	for(int i = 0; i <= Smax; ++i) {
		if(num < i) {
			ans += i - num;
			num = i;
		}
		num += S[i] - '0';
	}

	return to_string(ans);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": " << solve() << "\n";
	}

	return EXIT_SUCCESS;
}
