#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1000;

int a[MAXN][MAXN];
int row[MAXN], col[MAXN];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			row[i] = max(row[i], a[i][j]);
			col[j] = max(col[j], a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != min(row[i], col[j])) {
				printf("NO");
				return;
			}
		}
	}
	printf("YES");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}