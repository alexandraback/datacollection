#include <stdio.h>
#include <stdlib.h>

int main () {
	int i, j, k, l, m, n, o, p, q, r, s, t;
	char mat[60][60];
	
	scanf("%d", &t);
	for (s = 1; s <= t; s++) { 
		scanf("%d %d %d", &k, &l, &m);
		if (k == 1 || l == 1) {
			printf("Case #%d:\n", s);
			for (i = 0; i< k; i++) {
				for (j = 0; j < l; j ++) {
					if (m > 0) {
						printf("*");	
						m--;
					} else if (i == k-1 && j == l-1){
						printf("c");
					} else {
						printf(".");	
					}
				}	
				printf("\n");
			}
		} else {
			for (i = 0; i< k; i++) {
				for (j = 0; j < l; j ++) {
					mat[i][j] = '.';
				}
			}
			mat[0][0] =  'c';
			r = 0;
			o = k;
			p = l;
			while(m > 0) {
				if (o == 2 && p == 2) {
					if (m == 3) {
						mat[0][1] = '*';
						mat[1][0] = '*';
						mat[1][1] = '*';
					} else {
						break;	
					}	
				}
				if (o <= p) {
					if (m >= o) {
						for (i = 0; i < o; i++) {
						//	printf("%d %d \n", i, p);
							mat[i][p-1] = '*';
							m--;
						}
					} else {
						for (i = o-1; i > 1 && m != 0; i--) {
						//	printf("%d %d \n", i, p);
							mat[i][p-1] = '*';
							m--;	
						}
					}
					p--;
				} else {
					if (m >= p) {
						for (j = 0; j < p; j++) {
							//printf("3333 %d %d \n", o, j);
							mat[o-1][j] = '*';
							m--;
						}
					} else {
						for (j = p-1; j > 1 && m != 0; j--) {
							//printf("444 %d %d \n", o, j);
							mat[o-1][j] = '*';
							m--;	
						}
					}
					o--;	
				}
				/*printf("tot %d %d\n", o, p);
				for (i = 0; i< k; i++) {
					for (j = 0; j < l; j ++) {
						printf("%c", mat[i][j]);
					}	
					printf("\n");
				}
				printf("m %d\n", m);*/
			}
			if (m == 0) {
				printf("Case #%d:\n", s);
				for (i = 0; i< k; i++) {
					for (j = 0; j < l; j ++) {
						printf("%c", mat[i][j]);
					}	
					printf("\n");
				}
			} else {
				printf("Case #%d:\nImpossible\n", s);
			}
		}
	}
	return 0;	
}
