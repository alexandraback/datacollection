#include <stdio.h>

int varr[100];
int mat[100][10];

int
main(void) {
	int T, seq;
	int E, R, N;

	scanf("%d\n", &T);
	for (seq = 1; seq <= T; seq++) {
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &varr[i]);
		}

		int i, j;
		i = N;
		for (j = 0; j <= E; j++) {
			mat[i][j] = 0;	
		}
		
		for (i = N - 1; i >= 0; i--) {
			for (j = 0; j <= E; j++) {
				int v = 0;
				for (int k = 0; k <= j; k++) {
					int nj = (j - k) + R;	
					if (nj > E) 
						nj = E;
					int tot = k * varr[i];
					tot += mat[i + 1][nj];
					if (tot > v)
						v = tot;
				}
				mat[i][j] = v;
			}
		}
		printf("Case #%d: %d\n", seq, mat[0][E]);
	}
	return 0;
}
