// compile with c99

#include <stdio.h>
#include <stdlib.h>

void fill(char**a, int x, int y, int z, int t, char c) {
	for (int i = 0; i < z; ++i) {
		for (int j = 0; j < t; ++j) {
			a[x + i][y + j] = c;
		}
	}
}

int calc(char**a, int r, int c, int m) {
	int o = r * c - m;
	if (o == 1) {
		return 1;
	}
	if (r == 1) {
		fill(a, 0, 0, 1, o, '.');
		return 1;
	} 
	if (c == 1) {
		fill(a, 0, 0, o, 1, '.');
		return 1;
	}
	for (int ri = 2; ri <= r; ++ri)
		for (int ci = 2; ci <= c; ++ci)
			for (int rj = 2; rj <= ri; ++rj)
				for (int cj = 2; cj <= ci; ++cj) {
					if (ri * ci - (ri - rj) * (ci - cj) == o) {
						fill(a, 0, 0, ri, ci, '.');
						fill(a, rj, cj, ri - rj, ci - cj, '*');
						return 1;
					}
					if (rj > 2 && ci > 2 && ri * ci - (ri - rj) * (ci - cj) - 1 == o) {
						fill(a, 0, 0, ri, ci, '.');
						a[rj -1][ci - 1] = '*';
						fill(a, rj, cj, ri - rj, ci - cj, '*');
						return 1;
					}
					if (cj > 2 && ri > 2 && ri * ci - (ri - rj) * (ci - cj) - 1 == o) {
						fill(a, 0, 0, ri, ci, '.');
						a[ri -1][cj - 1] = '*';
						fill(a, rj, cj, ri - rj, ci - cj, '*');
						return 1;
					}
				}
					
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		int r, c, m;
		scanf("%d %d %d", &r, &c, &m);
		char**a = (char**) malloc(r * sizeof(char*));
		for(int j = 0; j < r; ++j) {
			a[j] = (char*) malloc(c * sizeof(char));
		}
		fill(a, 0, 0, r, c, '*');
		printf("Case #%d:\n", i);
		if (calc(a, r, c, m)) {
			for (int j = 0; j < r; ++j) {
				a[0][0] = 'c';
				for (int k = 0; k < c; ++k) {
					printf("%c", a[j][k]);
				}
				printf("\n");
			}
		}
		else {
			printf("Impossible\n");
		}
		for(int j = 0; j < r; ++j) {
			free(a[j]);
		}
		free(a);
	}
}
