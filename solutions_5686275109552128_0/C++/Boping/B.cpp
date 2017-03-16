#include <cstdio>
#include <cstdlib>

int P[1000], D;

int comp(const void * a, const void * b) {
	return *(int *)b - *(int *)a;
}

int main() {
	int t, T, i, m, n, a;
	FILE * fin = fopen("B.in", "r"), * fout = fopen("B.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d", &D);
		for (i = 0; i < D; ++i) {
			fscanf(fin, "%d", P + i);
		}
		qsort(P, D, 4, comp);
		a = P[0];
		for (m = P[0] - 2; m > 0; --m) {
			n = 0;
			for (i = 0; n + m < a && i < D && P[i] > m; ++i) {
				n += (P[i] - 1) / m;
			}
			if (n + m < a) {
				a = n + m;
			}
		}
		fprintf (fout, "Case #%d: %d\n", t, a);
	}
	return 0;
}
