#include <cstdio>

int k, c, s;

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%d%d", &k, &c, &s);
		if (c * s < k) {
			printf("Case #%d: IMPOSSIBLE\n", tt);
		} else {
			printf("Case #%d:", tt);
			for (int i = 0; i * c < k; i++) {
				int j = i * c;
				long long ans = 0;
				for (int p = 0; p < c; p++) {
					ans = ans * k + j;
					if (j + p < k) ans += p;
				}
				printf(" %lld", ans + 1);
			}
			printf("\n");
		}
	}
	return 0;
}
