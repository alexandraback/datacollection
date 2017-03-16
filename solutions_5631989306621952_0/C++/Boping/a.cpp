#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	FILE * fin = fopen("input.in", "r"), * fout = fopen("output.out", "w");
	int T, t, b, e;
	char s[2000], c;
	fscanf(fin, "%d\n", &T);
	for (t = 1; t <= T; ++t) {
		s[999] = getc(fin);
		b = 999;
		e = 1000;
		while ((c = getc(fin)) != '\n') {
			if (c < s[b]) {
				s[e] = c;
				++e;
			} else {
				s[b - 1] = c;
				--b;
			}
		}
		s[e] = '\0';
		fprintf(fout, "Case #%d: %s\n", t, s + b);
	}
	return 0;
}
