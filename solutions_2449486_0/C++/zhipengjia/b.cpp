
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int a[100][100];
bool row[100], column[100];

bool rowSame(int i, int x, int m) {
	for (int j = 0; j < m; j ++)
		if (column[j] && a[i][j] != x) return false;
	return true;
}

bool columnSame(int j, int x, int n) {
	for (int i = 0; i < n; i ++)
		if (row[i] && a[i][j] != x) return false;
	return true;
}

void work() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i ++)
		row[i] = true;
	for (int i = 0; i < m; i ++)
		column[i] = true;
	for (int x = 1; x <= 100; x ++) {
		for (int i = 0; i < n; i ++) {
			if (! row[i]) continue;
			for (int j = 0; j < m; j ++) {
				if (! column[j]) continue;
				if (a[i][j] != x) continue;
				bool f1 = rowSame(i, x, m);
				bool f2 = columnSame(j, x, n);
				if (! f1 && ! f2) {
					printf("NO\n");
					return;
				}
				if (f2) column[j] = false;
				if (f1) {
					row[i] = false;
					break;
				}
			}
		}
	}
	printf("YES\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		printf("Case #%d: ", test + 1);
		work();
	}

	return 0;
}