#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 120;

int g[maxn][maxn];
bool mark[maxn][maxn];
int n, m;

void init() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			scanf("%d", &g[i][j]);	
		}
	}
}

int work() {
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			bool max1 = true, max2 = true;
			for (int k = 0; k < n; k ++)
				if (k != i && g[k][j] > g[i][j]) { max1 = false; break; }
			for (int k = 0; k < m; k ++)
				if (k != j && g[i][k] > g[i][j]) { max2 = false; break; }
			if (!max1 && !max2) 
				return 0;
		}
	return 1;
}

int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti ++) {
		init();
		int ret = work();
		if (ret) printf("Case #%d: YES\n", ti); else printf("Case #%d: NO\n", ti);
	}
	return 0;
}
