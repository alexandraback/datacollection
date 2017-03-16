#include <cstdio>

int T, N, M, ret;
int lawn[100][100];

int lawnmower() {
	int A = 1;
	int B = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (lawn[k][j] > lawn[i][j]) {
					A = 0;
					break;
				}
			}
			for (int k = 0; k < M; k++) {
				if (lawn[i][k] > lawn[i][j]) {
					B = 0;
					break;
				}
			}
			if (!A && !B)
				return 0;
			A = 1;
			B = 1;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		scanf("%d", &M);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &lawn[j][k]);
			}
		}
		ret = lawnmower();
		printf("Case #%d: ", i);
		if (ret)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
