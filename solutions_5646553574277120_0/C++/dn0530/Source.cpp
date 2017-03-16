#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int T;
	FILE *fin, *fout;
	fin = fopen("input.in", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &T);
	for(int index = 1 ; index <= T ; index++) {
		int newcoin = 0;
		int original[100];
		int C, D, V;
		fscanf(fin, "%d %d %d", &C, &D, &V);
		for(int i = 0 ; i < D ; i++) {
			fscanf(fin, "%d", &original[i]);
		}

		if(original[0] != 1) {
			newcoin++;
		}
		long possible = 1 * C;
		
		int ci;
		if(newcoin == 0) {
			ci = 1;
		}
		else {
			ci = 0;
		}

		while(possible < V) {
			if(ci < D) {
				if(original[ci] > possible + 1) {
					newcoin++;
					possible = possible + (possible + 1) * C;
				}
				else {
					possible = possible + original[ci] * C;
					ci++;
				}
			}
			else {
				newcoin++;
				possible = possible + (possible + 1) * C;
			}
		}

		fprintf(fout, "Case #%d: %d\n", index, newcoin);
	}
	return 0;
}
