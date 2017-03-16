#include <cstdio>
#include <algorithm>
#define MAXN 128
using namespace std;
int m, n;
int a[MAXN][MAXN], lmax[MAXN][MAXN], rmax[MAXN][MAXN];
int umax[MAXN][MAXN], dmax[MAXN][MAXN];
int main() {
	int T;
	scanf("%d", &T);
	for(int cs = 1; cs <= T; ++cs) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				if(i == 0)
					umax[i][j] = a[i][j];
				else
					umax[i][j] = max(a[i][j], umax[i - 1][j]);
				if(j == 0)
					lmax[i][j] = a[i][j];
				else
					lmax[i][j] = max(a[i][j], lmax[i][j - 1]);
			}
		for(int i = n - 1; i >= 0; --i)
			for(int j = m - 1; j >= 0; --j) {
				if(i == n - 1)
					dmax[i][j] = a[i][j];
				else
					dmax[i][j] = max(a[i][j], dmax[i + 1][j]);
				if(j == m - 1)
					rmax[i][j] = a[i][j];
				else
					rmax[i][j] = max(a[i][j], rmax[i][j + 1]);
			}
		bool flag = true;
		for(int i = 0; i < n && flag; ++i)
			for(int j = 0; j < m && flag; ++j) {
				if(umax[i][j] <= a[i][j] && dmax[i][j] <= a[i][j] || lmax[i][j] <= a[i][j] && rmax[i][j] <= a[i][j])
					continue;
				else
					flag = false;
			}
		printf("Case #%d: %s\n", cs, flag ? "YES" : "NO");	
	}
	return 0;
}
