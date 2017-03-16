#include <cstdio>

int n, m, s[111][111];

void Check() {
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j) {
			bool row = true, col = true;
			for (int k = 0; k < m; ++ k)
				if (s[i][k] > s[i][j]) row = false;
			for (int k = 0; k < n; ++ k)
				if (s[k][j] > s[i][j]) col = false;
			if (!row && !col) {
				puts("NO");
				return;
			}
		}
	puts("YES");
}

int main() {
	freopen("t.in", "r", stdin);
	freopen("t.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++ t) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < m; ++ j) scanf("%d", &s[i][j]);
		printf("Case #%d: ", t + 1);
		Check();
	}
	return 0;
}
