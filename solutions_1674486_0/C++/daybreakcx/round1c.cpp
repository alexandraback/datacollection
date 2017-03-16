#include <stdio.h>
#include <string.h>
#define FILENAME "A-small-attempt1"
int ti, tn, i, j, k, n, m, get, ways[1000][1000];
char cross[1000][1000][1000];
int main()
{
	
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d", &n);
		memset(ways, 0, sizeof(ways));
		for (i = 0; i < n; ++i) {
			scanf("%d", &m);
			for (j = 0; j < m; ++j) {
				scanf("%d", &k);
				ways[i][k - 1] = 1;
			}
		}
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				for (k = 0; k < n; ++k)
					cross[i][j][k] = 0;
		for (k = 0; k < n; ++k)
			for (i = 0; i < n; ++i)
				if (i != k)
					for (j = 0; j < n; ++j)
						if (j != i && j != k && ways[i][k] && ways[k][j]) {
							ways[i][j] += ways[i][k] * ways[k][j];
							cross[i][k][j] = 1;
						}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j)
				if (j != i && ways[i][j] > 0) {
					get = 0;
					for (k = 0; k < n; ++k)
						if (k != i && k != j && cross[i][k][j]) {
							get = 1;
							if (ways[i][k] * ways[k][j] == ways[i][j])
								break;
						}
					if (get && k == n)
						break;
				}
			if (j != n)
				break;
		}
		printf(i == n ? "No\n" : "Yes\n");
	}
	return 0;
}