#include <stdio.h>
#ifdef DEBUG
	#define INPUT "B.in"
	#define OUTPUT "B.out"
#else
	#ifdef SMALL
		#define INPUT "B-small-attempt0.in"
		#define OUTPUT "B-small-attempt0.out"
	#else
		#ifdef LARGE
			#define INPUT "B-large.in"
			#define OUTPUT "B-large.out"
		#endif
	#endif
#endif

int n, m, lawn[120][120];

int
findmin(int *r, int *c) {
	int i, j, ret = 200;

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			if (lawn[i][j] < ret) {
				*r = i;
				*c = j;
				ret = lawn[i][j];
			}
	return ret;
}

int
cut(int r, int c, int operr, int mi) {
	int i, j;

	if (operr) {
		for (i = 0; i < m; ++i)
			if (lawn[r][i] != mi)
				return 0;
		for (i = r; i < n - 1; ++i)
			for (j = 0; j < m; ++j)
				lawn[i][j] = lawn[i + 1][j];
	} else {
		for (i = 0; i < n; ++i)
			if (lawn[i][c] != mi)
				return 0;
		for (j = c; j < m - 1; ++j)
			for (i = 0; i < n; ++i)
				lawn[i][j] = lawn[i][j + 1];
	}
	return 1;
}

int
main()
{
	int ti, tn, i, j, mi, can;
	FILE *inp, *oup;

	if ((inp = fopen(INPUT, "r")) == NULL) {
		fprintf(stderr, "Failed to open the input file\n");
		return -1;
	}
	if ((oup = fopen(OUTPUT, "w")) == NULL) {
		fprintf(stderr, "Failed to open the output file\n");
		return -1;
	}
	fscanf(inp, "%d\n", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fscanf(inp, "%d%d", &n, &m);
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
				fscanf(inp, "%d", &lawn[i][j]);
		while (1) {
			mi = findmin(&i, &j);
			can = 0;
			if (cut(i, j, 1, mi)) {
				--n;
				can = 1;
			}
			if (n == 0)
				break;
			if (cut(i, j, 0, mi)) {
				--m;
				can = 1;
			}
			if (m == 0)
				break;
			if (!can)
				break;
		}
		if (m && n)
			fprintf(oup, "Case #%d: NO\n", ti);
		else
			fprintf(oup, "Case #%d: YES\n", ti);
	}
	fclose(inp);
	fflush(oup);
	fclose(oup);
	return 0;
}
