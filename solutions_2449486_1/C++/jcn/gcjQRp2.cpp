#include<stdio.h>

int ntest;
int n, m;
int a[105][105];
int x[105], y[105];

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("BL.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d", &n, &m);

		for(int i=0; i<n; i++) x[i] = 0;
		for(int i=0; i<m; i++) y[i] = 0;

		for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
			scanf("%d", &a[i][j]);

			if(a[i][j] > x[i]) x[i] = a[i][j];
			if(a[i][j] > y[j]) y[j] = a[i][j];
		}
		bool ok = true;
		for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
			if(a[i][j] < x[i] && a[i][j] < y[j]) {
				ok = false;
			}
		}

		printf("Case #%d: %s\n", test, ok ? "YES" : "NO");
	}
	return 0;
}