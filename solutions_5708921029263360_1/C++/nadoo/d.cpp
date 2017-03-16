#include<stdio.h>


int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int m, n, i, j, k;
	int t, ti;
	int jn, pn, sn, kn;
	scanf("%d", &t);
	for (ti = 0; ti < t; ti++) {
		printf("Case #%d: ", ti + 1);
		scanf("%d %d %d %d", &jn, &pn, &sn, &kn);
		int ans, ans1, ans2;
		ans1 = jn*pn*kn;
		ans2 = jn*pn*sn;
		if (ans1 >= ans2) {
			printf("%d\n", ans2);
			for (i = 1; i <= jn; i++) {
				for (j = 1; j <= pn; j++) {
					for (k = 1; k <= sn; k++) {
						printf("%d %d %d\n", i, j, k);
					}
				}
			}
		}
		else {
			printf("%d\n", ans1);
			for (i = 1; i <= jn; i++) {
				for (j = 1; j <= pn; j++) {
					for (k = 1; k <= kn; k++) {
						printf("%d %d %d\n", i, j, ((i + j - 2)*kn + k - 1) % sn + 1);
					}
				}
			}
		}
	}
	return 0;


}