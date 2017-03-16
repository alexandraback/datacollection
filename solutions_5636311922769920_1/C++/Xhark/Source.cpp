#pragma warning(disable:4996)
#include <stdio.h>
typedef long long LL;
int main() {
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T, K, C, S;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d %d", &K, &C, &S);
		printf("Case #%d:", tc);
		int needS = (K + C - 1) / C;
		if (needS > S) {
			printf(" IMPOSSIBLE");
		}
		else {
			LL unit = 1;
			for (int g = 1; g < C; g++) {
				unit *= (LL)K;
			}
			LL go = 0;
			for (int i = 0; i < needS; i++) {
				LL nit = unit;
				LL num = 1;
				for (int c = 0; c < C; c++) {
					num += go * nit;
					go = (go + 1) % K;
					nit /= K;
				}
				printf(" %lld", num);
			}
		}
		printf("\n");
	}
	return 0;
}