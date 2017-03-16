// Problem B. Lawnmower
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;

int n, m;
int a[MAXN][MAXN], row[MAXN][MAXN], col[MAXN][MAXN];

int main() {
	int T;
	scanf("%d", &T);
	for (int run = 1; run <= T; run++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 0; i < n; ++i) {
			row[i][0] = a[i][0];
			for (int j = 1; j < m; ++j) {
				row[i][j] = max(row[i][j-1], a[i][j]);
			}
			row[i][m-1] = max(row[i][m-1], a[i][m-1]);
			for (int j = m-2; j >= 0; --j) {
				row[i][j] = max(row[i][j], max(row[i][j+1], a[i][j]));
			}
		}
		for (int j = 0; j < m; ++j) {
			col[0][j] = a[0][j];
			for (int i = 1; i < n; ++i) {
				col[i][j] = max(col[i-1][j], a[i][j]);
			}
			col[n-1][j] = max(col[n-1][j], a[n-1][j]);
			for (int i = n-2; i >= 0; --i) {
				col[i][j] = max(col[i][j], max(col[i+1][j], a[i][j]));
			}
		}
		bool can = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] < row[i][j] && a[i][j] < col[i][j]) {
					can = false;
					break;
				}
			}
			if (!can) break;
		}
		printf("Case #%d: %s\n", run, can ? "YES" : "NO");
	}
	return 0;
}
