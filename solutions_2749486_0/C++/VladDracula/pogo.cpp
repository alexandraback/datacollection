#include <stdio.h>

#define INFILE		"pogo.in"
#define OUTFILE		"pogo.out"

char res[4*(1<<20)];

int abs(int a) {
	return a < 0 ? -a : a;
}

void solve(FILE *fin, FILE *fout) {
	int tests;
	fscanf(fin, "%d", &tests);
	for (int t=0; t<tests; t++) {
		int x, y;
		fscanf(fin, "%d%d", &x, &y);

		int pos = 0;
		char first = 'N', second = 'S';
		if (y > 0) {
			first = 'S';
			second = 'N';
		}
		for (int i=0; i<abs(y); i++, pos+=2) {
			res[pos] = first;
			res[pos+1] = second;
		}

		first = 'E';
		second = 'W';
		if (x > 0) {
			first = 'W';
			second = 'E';
		}
		for (int i=0; i<abs(x); i++, pos+=2) {
			res[pos] = first;
			res[pos+1] = second;
		}

		res[pos] = 0;

		fprintf(fout, "Case #%d: %s\n", t+1, res);
	}
}

int main() {
	FILE *fin = fopen(INFILE, "r");
	FILE *fout = fopen(OUTFILE, "w");
	if (!fin) {
		printf("Cannot open input file!\n");
		return 0;
	}
	if (!fout) {
		printf("Cannot open output file!\n");
		return 0;
	}

	solve(fin, fout);

	fclose(fin);
	fclose(fout);
	return 0;
}
