#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 110, maxm = 110;
int n, m;
int a[maxn][maxm];
bool f[maxn][maxm];
int row[maxn];
int col[maxm];

bool solve() {
	scanf("%d %d", &n, &m);
	memset(row, 0, n * sizeof(int));
	memset(col, 0, m * sizeof(int));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			f[i][j] = false;
			scanf("%d", &a[i][j]);
			if(a[i][j] > 100 || a[i][j] == 0)
				return false;
			row[i] = max(row[i], a[i][j]);
			col[j] = max(col[j], a[i][j]);
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(a[i][j] != row[i] && a[i][j] != col[j])
				return false;
		}
	}
	return true;
}

int main(int argc, char **argv) {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for(int t = 1; t <= tt; ++t) {
		printf("Case #%d: ", t);
		if(solve()) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		scanf("\n");
	}
	return 0;
}
