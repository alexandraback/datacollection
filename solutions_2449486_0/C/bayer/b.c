#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp_in, *fp_out;
	int T;
	int N, M;
	int lawn[101][101];
	int i, j, k;
	int max_col, max_row;

	fp_in = fopen(argv[1], "r");
	if (fp_in == NULL) {
		perror(argv[1]);
		exit(1);
	}

	fp_out = fopen(argv[2], "w");
	if (fp_out == NULL) {
		perror(argv[2]);
		exit(1);
	}

	fscanf(fp_in, "%d ", &T);

	for (i = 0; i < T; i++) {
		fscanf(fp_in, "%d %d ", &N, &M);
		for (j = 0; j < N; j++) {
			max_row = 0;
			for (k = 0; k < M; k++) {
				fscanf(fp_in, "%d ", &lawn[j][k]);
				if (lawn[j][k] > max_row)
					max_row = lawn[j][k];
			}
			lawn[j][100] = max_row;
		}
		for (k = 0; k < M; k++) {
			max_col = 0;
			for (j = 0; j < N; j++) {
				if (lawn[j][k] > max_col)
					max_col = lawn[j][k];
			}
			lawn[100][k] = max_col;
		}

		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				if (lawn[j][k] < lawn[j][100] && lawn[j][k] < lawn[100][k])
					goto no;
			}
		}
		fprintf(fp_out, "Case #%d: YES\n", i+1);
		continue;
no:
		fprintf(fp_out, "Case #%d: NO\n", i+1);
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
