#include <stdio.h>
#include <memory.h>

bool m[2300000];
bool n[2300000];
int ss[2300000];

int main() {

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int cases, N, a[22];
	scanf("%d", &cases);

	for (int cas = 1; cas <= cases; cas++) {
		
		memset(n, 0, sizeof(n));
		n[0] = m[0] = 1;
		ss[0] = 0;
		bool ok = 0;
		scanf("%d", &N);
		printf("Case #%d:\n", cas);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		int k;
		for (int i = 0; i < N; i++) {
			memcpy(m, n, sizeof(n));
			if (ok) break;
			for (int j = 0; j <= 2000000; j++) {
				if (ok) break;
				if (m[j]) {
					if (m[j+a[i]]) {
						printf("%d", a[i]);
						k = j;
						while(k != ss[k]) {
							printf(" %d", k - ss[k]);
							k = ss[k];
						}
						printf("\n");
						k = j+a[i];
						printf("%d", k - ss[k]);
						k = ss[k];
						while(k != ss[k]) {
							printf(" %d", k - ss[k]);
							k = ss[k];
						}
						ok = 1;
						printf("\n");
					}
					else {
						n[j+a[i]] = 1;
						ss[j+a[i]] = j;
					}
				}
			}
		}
		if (!ok) printf("Impossible\n");
	}
	return 0;
}
