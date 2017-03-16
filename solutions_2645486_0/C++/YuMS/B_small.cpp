#include <cstdio>
#include <cstring>
#define MAX(x, y) (x > y) ? x : y

int values[11];
int max[2][10];
int deal() {
	int E, R, N;
	int p;
	scanf("%d%d%d", &E, &R, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &values[i]);
	}
	memset(max, 0, sizeof(max));
	for (int i = 0; i <= E; i++) {
		max[0][i] = values[0] * (E - i);
	}
	p = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= E - R; j++) {
			for (int k = MAX(0, j - R); k <= E - R; k++) {
				int tmp = (k + R - j) * values[i] + max[1 - p][k];
				if (tmp > max[p][j]) {
					max[p][j] = tmp;
				}
			}
			//printf("max[%d][%d]=%d\n", i, j, max[p][j]);
		}
		p = 1 - p;
	}
	return max[1 - p][0];
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: %d\n", i + 1, deal());
	}
	return 0;
}
