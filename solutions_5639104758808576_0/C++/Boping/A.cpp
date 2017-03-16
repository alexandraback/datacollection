#include <cstdio>

int main() {
	int t, T, m, c, a, i;
	FILE * fin = fopen("A.in", "r"), * fout = fopen("A.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d ", &m);
		c = 0;
		a = 0;
		for (i = 0; i <= m; ++i) {
			if (c < i) {
				++c;
				++a;
			}
			c += getc(fin) - '0';
		}
		fprintf(fout, "Case #%d: %d\n", t, a);
	}
	return 0;
}
