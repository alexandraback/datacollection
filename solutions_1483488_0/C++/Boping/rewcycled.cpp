#include <cstdio>

int main() {
	FILE * fin = fopen("recycled.in", "r"), * fout = fopen("recycled.out", "w");
	int T, t, a, b, d, i, j, x;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d", &a, &b);
		for (d = 1000000; a < d; d /= 10);
		x = 0;
		for (i = a; i < b; ++i) {
			for (j = (i % 10) * d + i / 10; j != i; j = (j % 10) * d + j / 10) {
				if (j > i && j <= b) {
					++x;
				}
			}
		}
		fprintf(fout, "Case #%d: %d\n", t, x);
	}
	return 0;
}
