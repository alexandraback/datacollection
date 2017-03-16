#include <cstdio>

int main() {
	int T, t, R, C, W;
	FILE * fin = fopen("A.in", "r"), * fout = fopen("A.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d%d", &R, &C, &W);
		fprintf(fout, "Case #%d: %d\n", t, (C / W) * R - (C % W ? 0 : 1) + W);
	}
	return 0;
}
