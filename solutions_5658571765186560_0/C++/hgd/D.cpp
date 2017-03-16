#include <cstdio>
#include <cstdlib>
#include <cctype>

bool work(int x, int r, int c) {
	switch (x) {
		case 1: return true;
		case 2: return (r * c) % 2 == 0;
		case 3: return ((r * c) % 3 == 0) && (r >= 2) && (c >= 2);
		case 4: return ((r * c) % 4 == 0) && (r >= 3) && (c >= 3);
		case 5: return ((r * c) % 5 == 0) && (r >= 3) && (c >= 3);
		case 6: return ((r * c) % 6 == 0) && (r >= 4) && (c >= 4);
	}
	return false;
}

int main() {
	FILE *fp = fopen("D-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, x, r, c;
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d %d %d", &x, &r, &c);
		if (work(x, r, c))
			fprintf(fout, "Case #%d: GABRIEL\n", i + 1);
		else
			fprintf(fout, "Case #%d: RICHARD\n", i + 1);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}