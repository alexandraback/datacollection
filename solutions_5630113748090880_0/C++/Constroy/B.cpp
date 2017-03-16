#include <cstdio>

int T, n, h, c[2509];

int main() {
	scanf("%d", &T);
	for (int iT = 1; iT <= T; ++iT) {
		printf("Case #%d:", iT);
		scanf("%d", &n);
		for (int i = 1; i < 2 * n; ++i)
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &h);
				++c[h];
			}
		for (int i = 1; i <= 2500; ++i) {
			if (c[i] & 1) printf(" %d", i);
			c[i] = 0;
		}
		putchar('\n');
	}
	return 0;
}
