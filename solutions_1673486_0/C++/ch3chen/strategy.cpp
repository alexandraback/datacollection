#include <stdio.h>
#include <stdlib.h>

double Expectation1(double *prob, int typed, int total);
double Expectation2(double *prob, int typed, int backspace, int total);

int main(int argc, char* argv[])
{
	FILE *fp = fopen(argv[1], "r");
	FILE *ofp = fopen(argv[2], "w");

	int case_cnt;
	fscanf(fp, "%d", &case_cnt);
	for(int i = 1; i <= case_cnt; i++)
	{
		int letter_typed;
		int letter_total;
		fscanf(fp, "%d %d", &letter_typed, &letter_total);
//		printf("typed=%d, total=%d\n", letter_typed, letter_total);

		double probability[letter_typed];
		for(int j = 0; j < letter_typed; j++)
		{
			fscanf(fp, "%lf", &probability[j]);
//			printf("%lf ", possibility[j]);
		}
//		printf("\n");

		double exp_min = letter_total + 2;
		double exp = Expectation1(probability, letter_typed, letter_total);
		exp_min = exp < exp_min ? exp : exp_min;

		for(int j = 1; j <= letter_typed; j++)
		{
			exp = Expectation2(probability, letter_typed, j, letter_total);
			exp_min = exp < exp_min ? exp : exp_min;
		}

		fprintf(ofp, "Case #%d: %f\n", i, exp_min);
	}

	fclose(fp);
	fclose(ofp);
}

double Expectation1(double *prob, int typed, int total)
{
	double prob_correct = 1;
	for(int i = 0; i < typed; i++)
		prob_correct *= prob[i];

	int to_type = total - typed + 1;
	double expect = prob_correct * to_type + (1 - prob_correct) * (to_type + total + 1);
	return expect;
}

double Expectation2(double *prob, int typed, int backspace, int total)
{
	if(backspace > typed)
		return 0;
	else if(typed == backspace)
		return backspace + total + 1;
	else
	{
		double prob_correct = 1;
		int remain = typed - backspace;
		for(int i = 0; i < remain; i++)
			prob_correct *= prob[i];
		
		int to_type = total - typed + 1;
		double expect = prob_correct * (to_type + backspace + backspace)
				      + (1 - prob_correct) * (to_type + backspace + backspace + total + 1);

		return expect;
	}
}
