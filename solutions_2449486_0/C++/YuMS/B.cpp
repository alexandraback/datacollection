#include <cstdio>
#include <cstring>

int main() {
	int T, N, M;
	int a[101][101];
	int maxH[101];
	int maxV[101];
	int now;
	bool valid;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		valid = true;
		scanf("%d%d", &N, &M);
		memset(maxH, 0, sizeof(maxH));
		memset(maxV, 0, sizeof(maxV));
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &now);
				a[j][k] = now;
				if (maxH[j] < now) {
					maxH[j] = now;
				}
				if (maxV[k] < now) {
					maxV[k] = now;
				}
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				//printf("j = %d, k = %d ", j, k);
				//printf("maxH = %d, maxV = %d ", maxH[j], maxV[k]);
				//printf("a[j][k] = %d\n", a[j][k]);
				if (maxH[j] > a[j][k] && maxV[k] > a[j][k]) {
					valid = false;
				}
			}
		}
		printf("Case #%d: %s\n", i + 1, valid ? "YES" : "NO");
	}
	return 0;
}
