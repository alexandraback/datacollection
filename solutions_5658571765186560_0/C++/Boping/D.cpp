#include <cstdio>

#define YES fprintf(fout, "GABRIEL\n")
#define NO fprintf(fout, "RICHARD\n")

int main() {
	int t, T, x, r, c, a;
	FILE * fin = fopen("D.in", "r"), * fout = fopen("D.out", "w");
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d %d %d", &x, &r, &c);
		if (r > c) {
			a = c;
			c = r;
			r = a;
		}
		fprintf(fout, "Case #%d: ", t);
		if ((r * c) % x) {
			NO;
		} else if (x < 3) {
			YES;
		} else if (x == 3) {
			if (r == 1) {
				NO;
			} else {
				YES;
			}
		} else if (x == 4) {
			if (r < 3) {
				NO;
			} else {
				YES;
			}
		} else if (x == 5) {
			if (r < 3 || (r == 3 && c == 5)) {
				NO;
			} else {
				YES;
			}
		} else if (x == 6) {
			if (r < 4) {
				NO;
			} else {
				YES;
			}
		} else {
			NO;
		}
	}
	return 0;
}
