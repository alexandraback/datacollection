#include <cstdio>

int n;
int a[25];
int b[25], c[25], bn, cn;

void solve() {
	for (int i = 1; i < (1 << n); ++i) {
		int sum = 0; bn = 0;
		for (int k = 0; k < n; ++k) {
			if (i & (1 << k)) {
				sum += a[k];
				b[bn++] = a[k];
			}
		}
		for (int j = ((1 << n) - 1) & (~i); j > 0; j = (j - 1) & (~i)) {
			int tmp = 0, cn = 0;
			for (int l = 0; l < n; ++l) {
				if (j & (1 << l)) {
					tmp += a[l];
					c[cn++] = a[l];
				}
			}
			if (tmp == sum) {
				//printf("%d %d\n", bn, cn);
				//printf("%d %d\n", sum, tmp);
				for (int l = 0; l < bn; ++l) {
					printf(l == bn - 1 ? "%d\n" : "%d ", b[l]);
				}
				for (int l = 0; l < cn; ++l) {
					printf(l == cn - 1 ? "%d\n" : "%d ", c[l]);
				}
				return;
			}
		}
	}
	puts("Impossible");
}

int main() {
	int T; scanf("%d", &T);
	int cas = 0;
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		printf("Case #%d:\n", ++cas);
		solve();
	}
	return 0;
}
