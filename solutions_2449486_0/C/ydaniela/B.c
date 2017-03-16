#include <stdio.h>
#include <stdlib.h>

int main () {
	int i, j, k, l, m, n, o, p, q, r, s, t, X, O;
	int mat[105][105];
	
	scanf(" %d ", &t);
	for (o = 1; o <= t; o++) {
		scanf(" %d %d ", &n, &m);
		for ( i = 0; i < n; i++) {
			for (j = 0; j < m; j++)	 {
				scanf("%d", &mat[i][j]);
			}
		}
		
		for (k = 1; k < 100; k++) {
			for (i = 0; i < n; i++)	 {
				l = 1;
				for (j = 0; j < m; j++)	 {
					if(mat[i][j] != k && mat[i][j] != 101) {
						l = 0;
						break;
					}
				}
				if (l) {
					for (j = 0; j < m; j++)	 {
						mat[i][j] = 101;
					}
				}
			}
			for (j = 0; j < m; j++)	 {
				l = 1;
				for (i = 0; i < n; i++)	 {
					if(mat[i][j] != k && mat[i][j] != 101) {
						l = 0;
						break;
					}
				}
				if (l) {
					for (i = 0; i < n; i++) {
						mat[i][j] = 101;
					}
				}
			}
		}
		s = 1;
		for ( i = 0; i < n; i++) {
			for (j = 0; j < m; j++)	 {
				if (mat[i][j] != 101) {
					s = 0;
					break;	
				}
			}
			if(!s) {
				break;	
			}
		}
		if (s) {
			printf("Case #%d: YES\n", o);
		} else {
			printf("Case #%d: NO\n", o);	
		}
	}
	
	return 0;
}
