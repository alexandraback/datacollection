#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

int E, R, N;
int v[MAXN];

int dp[10][6];

int dfs(int i, int e) {
	if (dp[i][e] != -1) {
		return dp[i][e];
	}
	if (i == 0) {
		return dp[i][e] = (E - e) * v[i];
	}
	int ans = 0;
	for (int et = 0; et <= E; ++et) {
		int opt = dfs(i - 1, et);
		int use = min(et + R, E) - e;
		if (0 <= use && use <= min(et + R, E)) {
			if (opt + use * v[i] > ans) {
				ans = opt + use * v[i];
			}
		}
	}
	return dp[i][e] = ans;
}

int main() {
	int n_case;
	cin >> n_case;
	for (int index = 1; index <= n_case; ++index) {
		fill(dp[0], dp[10], -1);
		cin >> E >> R >> N;
		for (int i = 0; i < N; ++i) {
			cin >> v[i];
		}
		int ans = 0;
		for (int e = 0; e <= E; ++e) {
			int opt = dfs(N - 1, e);
			if (opt > ans) {
				ans = opt;
			}
		}
		printf("Case #%d: %d\n", index, ans);
	}
	return 0;
}
