#include <cstdio>

int main() {
	FILE * fin = fopen("d.in", "r"), * fout = fopen("d.out", "w");
	int t, T, K, C, S, i, j;
	long long p;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d%d", &K, &C, &S);
		fprintf(fout, "Case #%d:", t);
		if ((K + C - 1) / C > S) {
			fprintf(fout, " IMPOSSIBLE");
		} else {
			j = 0;
			p = 0;
			for (i = 0; i < K; ++i) {
				p += i;
				++j;
				if (j < C) {
					p *= K;
				} else {
					fprintf(fout, " %lld", p + 1);
					p = 0;
					j = 0;
				}
			}
			if (j) {
//				p /= K;
				fprintf(fout, " %lld", p + 1);
			}
		}
		fprintf(fout, "\n");
	}
	return 0;
}