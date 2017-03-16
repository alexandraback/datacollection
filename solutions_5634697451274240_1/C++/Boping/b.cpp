#include <cstdio>

int main() {
	FILE * fin = fopen("b.in", "r"), * fout = fopen("b.out", "w");
	int T, t, s0, s1, a;
	fscanf(fin, "%d\n", &T);
	for (t = 1; t <= T; ++t) {
		s0 = getc(fin);
		a = 0;
		while ((s1 = getc(fin)) != '\n') {
			if (s0 != s1) ++a;
			s0 = s1;
		}
		if (s0 == '-') ++a;
		fprintf(fout, "Case #%d: %d\n", t, a);
	}
	return 0;
}
