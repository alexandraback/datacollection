#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 103;
int g[maxn][maxn];
int row[maxn], col[maxn];
const char * ans [] = {"NO", "YES"};
int main(int argc, char *argv[]) {
	freopen ("B-large.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int cas;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		int n, m;
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				scanf ("%d", &g[i][j]);
			}
		}
		for (int i = 0; i < n; i ++) {
			row[i] = -1;
			for (int j = 0; j < m; j ++) {
				if (row[i] < g[i][j]) {
					row[i] = g[i][j];
				}
			}
		}
		for (int j = 0; j < m; j ++) {
			col[j] = -1;
			for (int i = 0; i < n; i ++) {
				if (col[j] < g[i][j]) {
					col[j] = g[i][j];
				}
			}
		}
		int flag = 1;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (g[i][j] != min (row[i], col[j])) {
					flag = 0;
					break;
				}
			}
		}
		printf ("Case #%d: %s\n", t, ans[flag]);
	}
	return 0;
}
