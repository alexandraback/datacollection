#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, n, m;
int a[111][111], d[111], e[111];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for (int tn = 0; tn < tc; tn++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		memset(d, 0, sizeof d);
		memset(e, 0, sizeof e);
		bool g = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				d[i] = max(d[i], a[i][j]);
				e[j] = max(e[j], a[i][j]);
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] < d[i] && a[i][j] < e[j]) {
					g = 0;
					break;
				}
		printf("Case #%d: ", tn+1);
		puts(g ? "YES" : "NO");
	}
	return 0;
}