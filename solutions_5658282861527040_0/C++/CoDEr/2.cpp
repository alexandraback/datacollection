#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//*
int main(void) {
	FILE * fp = NULL;
	FILE * fout = NULL;
	int t = 0;
	int a = 0, b = 0, c = 0;
	long long res = 0;

	if (fopen_s(&fp, "B-small-attempt0.in", "r") != NULL) return -1;
	if (fopen_s(&fout, "B-small.out", "w") != NULL) return -1;

	fscanf(fp, "%d", &t);
	for (int caseIndex = 1; caseIndex <= t; caseIndex++) {
		res = 0;
		fscanf(fp, "%d%d%d", &a, &b, &c);

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i & j) < c) res = res + 1;
			}
		}

		fprintf(fout, "Case #%d: %lld\n", caseIndex, res);
	}

	fclose(fout);
	fclose(fp);

	return 0;
}
//*/