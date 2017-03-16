#include <cstdio>

int main() {
	FILE * fin = fopen("dancing.in", "r"), * fout = fopen("dancing.out", "w");
	int T, t, n, s, p, tp, a;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d%d", &n, &s, &p);
		a = 0;
		while (n > 0) {
			fscanf(fin, "%d", &tp);
			if (tp >= 3 * p - 2) {
				++a;
			} else if (s > 0 && tp >= 3 * p - 4 && p != 1) {
				++a;
				--s;
			}
			--n;
		}
		fprintf(fout, "Case #%d: %d\n", t, a);
	}
	return 0;
}
