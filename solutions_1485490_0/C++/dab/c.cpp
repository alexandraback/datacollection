#include <cstdio>
#include <algorithm>

using namespace std;

#define X 100

int T, N, M, A[X], At[X], B[X], Bt[X], Ad[X][X], Bd[X][X], D[X][X];

main()
{
	scanf("%d\n", &T);

	for (int t = 1; t <= T; ++t) {
		scanf("%d %d\n", &N, &M);

		for (int n = 0; n < N; ++n) {
			scanf("%d %d\n", &A[n], &At[n]);
		}

		for (int m = 0; m < M; ++m) {
			scanf("%d %d\n", &B[m], &Bt[m]);
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				D[i][j] = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int d = 0, dx = 0;
				Ad[i][j] = A[i];
				Bd[i][j] = B[j];

				if (i > 0 && j > 0) {
					d = D[i-1][j-1];
				}
				if (i > 0) {
					d = max(d,D[i-1][j]);
					Bd[i][j] = Bd[i-1][j];
				}
				if (j > 0) {
					d = max(d,D[i][j-1]);
					Ad[i][j] = Ad[i][j-1];
				}
				if (At[i] == Bt[j]) {
					dx = min(Ad[i][j], Bd[i][j]);
					Ad[i][j] -= dx;
					Bd[i][j] -= dx;
				}
				D[i][j] = d + dx;
			}
		}

		printf("Case #%d: %d\n", t, D[N-1][M-1]);
	}
}
