#include <cstdio>

void solve(int K, int C, int S, FILE *ofp) {
	if (C * S < K){
		fprintf(ofp, "IMPOSSIBLE\n");
		return;
	}
	for (int i = 0; i < K; i += C) {
		long long x = 0;
		int j;
		for (j = i; j < i + C && j < K; ++j)
			x = x * K + j;
		fprintf(ofp, "%lld%c", x + 1, j == K ? '\n' : ' ');
	}
}

int main() {
	int T, K, C, S;
	FILE*ifp = fopen("D.in", "r");
	FILE *ofp = fopen("D.out", "w");
	fscanf(ifp, "%d", &T);
	for (int t = 1; t <= T; ++t) {
		fscanf(ifp, "%d%d%d", &K, &C, &S);
		fprintf(ofp, "Case #%d: ", t);
		solve(K, C, S, ofp);
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
