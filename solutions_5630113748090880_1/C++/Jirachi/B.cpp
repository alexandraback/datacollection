#include <bits/stdc++.h>

const int MAXN = 101;
const int MAXD = 10001;

int T, n, a[2 * MAXN][MAXN], c[MAXD];

int main() {
	freopen("B.in", "r", stdin);
	std::cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		std::cin >> n;
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= 2 * n - 1; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
				c[a[i][j]]++;
			}
		printf("Case #%d:", cs);
		for (int i = 1, cnt = n; i <= 2500 && cnt; i++)
			if (c[i] & 1) printf(" %d", i), cnt--;
		puts("");
	}
	return 0;
}
