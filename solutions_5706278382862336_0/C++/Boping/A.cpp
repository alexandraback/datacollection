#include <cstdio>

int main() {
	FILE * fin = fopen("A.in", "r"), * fout = fopen("A.out", "w");
	int T, t, g;
	long long P, Q, p, q, r;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%lld/%lld", &P, &Q);
		p = P;
		q = Q;
		while (r = q % p) {
			q = p;
			p = r;
		}
		P /= p;
		Q /= p;
		g = 1;
		while (!(Q & 1)) {
			Q /= 2;
			if (P < Q) {
				++g;
			}
		}
		if (Q != 1) {
			fprintf(fout, "Case #%d: impossible\n", t);
		} else {
			fprintf(fout, "Case #%d: %d\n", t, g);
		}
	}
	return 0;
}
