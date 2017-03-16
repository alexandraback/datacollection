#include <cstdio>
#include <cstring>

const int maxm = 3000;

int casei, cases, n, m;
int cnt[maxm];

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		for (int i = 1; i < n + n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &m);
				cnt[m] ^= 1;
			}
		}
		printf("Case #%d:", casei);
		for (int i = 1; i < maxm; ++i) if (cnt[i]) {
			printf(" %d", i);
			--n;
		}
		printf("\n");
		if (n != 0) printf("!\n!\n!\n");
	}
	return 0;
}
