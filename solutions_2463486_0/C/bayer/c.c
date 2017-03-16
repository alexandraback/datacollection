#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int FairSQ[5] = {1,4,9,121,484};

int main(int argc, char **argv)
{
	FILE *fp_in, *fp_out;
	int T;
	int A, B;
	int i;
	int k;
	int dl, ul;

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
		fscanf(fp_in, "%d %d ", &A, &B);
		for (k = 0; k < 5; k++)
			if (FairSQ[k] >= A) {
				break;
			}
		dl = k;
		for (k = 4; k >= dl; k--) {
			if (FairSQ[k] <= B) {
				break;
			}
		}
		ul = k;
		
		fprintf(fp_out, "Case #%d: %d\n", i+1, ul-dl+1);
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
