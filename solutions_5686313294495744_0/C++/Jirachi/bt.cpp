#include <bits/stdc++.h>

const int MAXN = 101;
const int MAXS = 100001;

int T, n, dp[MAXS];
std::string s[MAXN][2];

bool checker(const int &state, int x) {
	bool flag1 = false, flag2 = false;
	for (int i = 1; i <= n; i++) {
		if (state & (1 << i - 1)) {
			if (s[x][0] == s[i][0]) flag1 = true;
			if (s[x][1] == s[i][1]) flag2 = true;
		}
	}
	return flag1 && flag2;
}

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			std::cin >> s[i][0] >> s[i][1];
		}
		memset(dp, 0, sizeof(dp));
		for (int s = 0; s < (1 << n); s++) {
			for (int i = 1; i <= n; i++) {
				if (s & (1 << i - 1)) continue;
				dp[s | (1 << i - 1)] = std::max(dp[s | (1 << i - 1)], dp[s] + checker(s, i));
			}
		}
		printf("Case #%d: %d\n", cs, dp[(1 << n) - 1]);
	}
	return 0;
}
