#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int T;
	FILE *fin, *fout;
	fin = fopen("input.in", "r");
	fout = fopen("output.txt", "w");
	//scanf("%d", &T);
	fscanf(fin, "%d", &T);
	for(int i = 0 ; i < T ; i++) {
		int R, C, W;
		//scanf("%d %d %d", &R, &C, &W);
		fscanf(fin, "%d %d %d", &R, &C, &W);
		fprintf(fout, "Case #%d: %d\n", i + 1, (C/W)*(R-1) + (C-1)/W + W);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}