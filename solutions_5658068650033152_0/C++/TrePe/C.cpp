#include <stdio.h>

int cases, kejs;
int i, j;
int n, m, k, nm;
char a[22][22];

void fill(int i, int j) {
	if (a[i][j] != 0) return;
	a[i][j] = 2;
	fill(i+1,j);
	fill(i-1, j);
	fill(i,j+1);
	fill(i,j-1);
}

bool valid() {
	int i, j;
	for (i = 1; i <= n; i++) {
		if (a[i][1] == 0) fill(i, 1);
		if (a[i][m] == 0) fill(i, m);
	}
	for (j = 1; j <= m; j++) {
		if (a[1][j] == 0) fill(1, j);
		if (a[n][j] == 0) fill(n, j);
	}
	int c = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i][j] != 2) c++;
		}
	}
	return c >= k;
}

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        fprintf(stderr, "Case #%d: ", kejs);
				scanf("%d%d%d", &n, &m, &k);
				nm = n * m;
				for (i = 0; i <= n+1; i++) {
					for (j = 0; j <= m+1; j++) {
						a[i][j] = 2;
					}
				}
				int best = 1234567890;
				for (int ii = 0; ii < (1 << nm); ii++) {
					//fprintf(stderr, "%d\n", ii);
					int c = 0, cnt = 0;
					for (i = 1; i <= n; i++) {
						for (j = 1; j <= m; j++) {
							if ((1 << c) & ii) {
								a[i][j] = 1;
								cnt++;
							} else a[i][j] = 0;
							c++;
						}
					}
					//if (cnt >= best) continue;
					if (valid() && cnt < best) {
						best = cnt;
					}
				}
				printf("%d\n", best);
    }
    return 0;
}
