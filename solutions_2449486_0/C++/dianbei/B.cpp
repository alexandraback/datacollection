#include <stdio.h>
#include <string.h>

int a[200][200];
int xm[200], ym[200];
int n, m;

inline int MAX(int a, int b) {
	return a < b ? b : a;
}

bool yes() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < xm[i] && a[i][j] < ym[j]) return false;
		}
	}
	return true;
}

int main() {
	int re, ri = 1;

	// freopen("D:\\Work\\GCJ2013\\A-large.in", "r", stdin);
	// freopen("D:\\Work\\GCJ2013\\A-large.out", "w", stdout);

	scanf("%d", &re);
	while(re--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		for (int j = 0; j < m; j++) {
			ym[j] = -1;
			for (int i = 0; i < n; i++) {
				if (a[i][j] > ym[j]) ym[j] = a[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			xm[i] = -1;
			for (int j = 0; j < m; j++) {
				if (a[i][j] > xm[i]) xm[i] = a[i][j];
			}
		}


		printf("Case #%d: ", ri++);
		if (yes()) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
