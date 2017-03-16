#include <cstdio>
#include <cstring>

const char s1[] = "IMPOSSIBLE";
const char s2[] = "POSSIBLE";

int n;
long long m;
int a[50][50];

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%lld", &n, &m);
		if (m > (1ll << (n - 2))) {
			printf("Case #%d: %s\n", tt, s1);
			continue;
		}
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				a[i][j] = 1;
		if (m != (1ll << (n - 2))) {
			a[0][n - 1] = 0;
			for (int i = 0; i < n - 1; i++) {
				if (m & (1ll << i)) a[i + 1][n - 1] = 1;
				else a[i + 1][n - 1] = 0;
			}
		}
		printf("Case #%d: %s\n", tt, s2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) printf("%d", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
