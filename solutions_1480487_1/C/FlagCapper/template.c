#include "lib.h"

int main(int argc, char *argv[]) {

	if (argc != 3) {
		return 1;
	}

	FILE *input = fopen(argv[1], "r");
	FILE *output = fopen(argv[2], "w");

	multi case_number = get_multi(input, '\n');

	int i;

	for (i = 0; i < case_number.i; ++i) {
		int j;

		multi pNum = get_multi(input, ' ');
		multi scores[pNum.i];

		double X = 0;

		for (j = 0; j < pNum.i - 1; ++j) {
			scores[j] = get_multi(input, ' ');
			X += scores[j].i;
		}
		scores[j] = get_multi(input, '\n');
		X += scores[j].i;

		fprintf(output, "Case #%i: ", i + 1);

		for (j = 0; j < pNum.i; ++j) {
			if (j > 0)
				fprintf(output, " ");

			double basicAvg = (2*X)/((double) pNum.i);
			int ignoreNum = 0;
			double ignoreSum = 0;

			int k;

			for (k = 0; k < pNum.i; ++k) {
				if ((double) scores[k].i >= basicAvg) {
					++ignoreNum;
					ignoreSum += (double) scores[k].i;
				}
			}

			double advancedAvg = (X + (X - ignoreSum))/((double) (pNum.i - ignoreNum));

			double lPer = ((advancedAvg - ((double)scores[j].i))/X);

			if (lPer < 0)
				lPer = 0;

			fprintf(output, "%f", lPer*100.0);
		}
		fprintf(output, "\n");
	}


	fclose(input);
	fclose(output);

	return 0;
}
