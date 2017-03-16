#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int main() {
	FILE * fin = fopen("input.in", "r"), * fout = fopen("output.out", "w");
	int T, t, n, h[2500], i, j, k;
	fscanf(fin, "%d\n", &T);
	for (t = 1; t <= T; ++t) {
		memset(h, 0, 2500 * sizeof(int));
		fscanf(fin, "%d", &n);
		for (i = 0; i < 2 * n - 1; ++i) {
			for (j = 0; j < n; ++j) {
				fscanf (fin, "%d", &k);
				++h[k - 1];
			}
		}
		fprintf(fout, "Case #%d:", t);
		for (i = 0; i < 2500; ++i) {
			if (h[i] & 1) {
				fprintf(fout, " %d", i + 1);
			}
		}
		fprintf(fout, "\n");
	}
	return 0;
}
