#include <bits/stdc++.h>

const int MAXN = 101;

int T, b, answer[MAXN][MAXN];
long long m;

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	std::cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		std::cin >> b >> m;
		printf("Case #%d: ", cs);
		memset(answer, 0, sizeof(answer));
		if (m > (1 << b - 2)) {
			puts("IMPOSSIBLE");
		} else {
			puts("POSSIBLE");
			for (int i = 2; i < b; i++) {
				for (int j = 1; j < i; j++)
					answer[j][i] = 1;
			}
			answer[1][b] = 1;
			m--;
			for (int i = 0; i <= b - 3; i++) {
				if ((m >> i) & 1) {
					answer[i + 2][b] = 1;
				}
			}
			for (int i = 1; i <= b; i++) {
				for (int j = 1; j <= b; j++) {
					printf("%d", answer[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}
