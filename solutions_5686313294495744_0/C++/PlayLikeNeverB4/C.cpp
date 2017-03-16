#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024

int N;
string A[MAXN], B[MAXN];
int dp[1 << 16];
set<string> as, bs;

int solve() {
	memset(dp, 0, sizeof(dp));

	for (int mask = 0; mask < (1 << N); mask++) {
		as.clear();
		bs.clear();
		for (int i = 0; i < N; i++) {
			if ((mask & (1 << i)) > 0) {
				as.insert(A[i]);
				bs.insert(B[i]);
			}
		}

		for (int i = 0; i < N; i++) {
			if ((mask & (1 << i)) == 0) {
				int f = 0;
				if (as.count(A[i]) > 0 && bs.count(B[i]) > 0) {
					f = 1;
				}
				int nmask = mask | (1 << i);
				dp[nmask] = max(dp[nmask], dp[mask] + f);
			}
		}
	}

	return dp[(1 << N) - 1];
}

int main() {
	assert(freopen("C.in", "r", stdin));
	assert(freopen("C.out", "w", stdout));
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i] >> B[i];
		}

		int ans = solve();
		cout << ans << '\n';
		
		cerr << t << endl;
	}

	return 0;
}
