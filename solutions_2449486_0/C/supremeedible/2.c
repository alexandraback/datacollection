#include <stdio.h>
//#define DEBUG

main() {
	int T, N, M, Q, i, j, J;
	scanf(" %d", &T);

	for(Q = 1; Q <= T; Q++) {
		scanf(" %d %d", &N, &M);

		int I[N * M];
		int rows[N];
		int cols[M];
		int nonzeros = N * M;
		int action;

		for(i = 0; i < N; i++) rows[i] = 0;
		for(i = 0; i < M; i++) cols[i] = 0;

		for(i = 0; i < N * M; i++) scanf(" %d", I + i);

		restart:
		action = 0;

		for(i = 0; i < N; i++) {
			if(rows[i]) continue;
			int a = 0;

			for(j = 0; j < M; j++) {
				if(I[i * M + j] > 0) {
					if(a == 0) {
						a = I[i * M + j];
					} else if(a != I[i * M + j]) {
						a = 101;
						break;
					}
				}
			}

			if(a < 101) {
				for(j = 0; j < M; j++) {
					if(I[i * M + j] < -a) {
						a = 101;
						break;
					}
				}
			}

			if(a < 101) {
				rows[i] = 1;
				action = 1;
				for(j = 0; j < M; j++) {
					if(I[i * M + j] > 0) {
						nonzeros--;
						I[i * M + j] = -I[i * M + j];
					}
				}
#ifdef DEBUG
				printf("Row %d\n", i);
#endif
			}
		}

		for(i = 0; i < M; i++) {
			if(cols[i]) continue;
			int a = 0;

			for(j = 0; j < N; j++) {
				if(I[j * M + i] > 0) {
					if(a == 0) {
						a = I[j * M + i];
					} else if(a != I[j * M + i]) {
						a = 101;
						break;
					}
				}
			}

			if(a < 101) {
				for(j = 0; j < N; j++) {
					if(I[j * M + i] < -a) {
						a = 101;
						break;
					}
				}
			}

			if(a < 101) {
				cols[i] = 1;
				action = 1;
				for(j = 0; j < N; j++) {
					if(I[j * M + i] > 0) {
						nonzeros--;
						I[j * M + i] = -I[j * M + i];
					}
				}
#ifdef DEBUG
				printf("Col %d\n", i);
#endif
			}
		}

		if(nonzeros == 0) {
			printf("Case #%d: YES\n", Q);
		} else if(action) {
#ifdef DEBUG
			printf("nonzeros = %d\n", nonzeros);
			printf("Restart\n");
#endif
			goto restart;
		} else {
#ifdef DEBUG
			printf("nonzeros = %d\n", nonzeros);
#endif
			printf("Case #%d: NO\n", Q);
		}
	}
}
