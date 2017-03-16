#include <cstdio>
#include <cstring>
int o[53][53];
long long wa[53];
int main() {
	int t;
	int n;
	long long m;
	int i, j;
	int cnt = 0;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	wa[0] = wa[1] = 1;
	for (i = 2; i <= 50; i++) wa[i] = wa[i - 1] << 1;
	while (t--) {
		scanf("%d %lld", &n, &m);
		printf("Case #%d: ",++cnt);
		if (wa[n - 1] < m) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		memset(o, 0, sizeof(o));
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n - 1; j++) {
				o[i][j] = 1;
			}
		}
		for (i = n - 2; i >= 0; i--) {
			if (m - wa[i] >= 0) {
				m -= wa[i];
				o[i][n - 1] = 1;
			}
		}
		printf("POSSIBLE\n");
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d", o[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}