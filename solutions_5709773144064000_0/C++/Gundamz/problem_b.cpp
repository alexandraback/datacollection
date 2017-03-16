#include <stdio.h>

int main()
{
	int num_of_test;
	FILE *f = fopen("B-small-attempt1.in", "r");
	FILE *out = fopen("B-small-attempt1.out", "w");
	fscanf(f, "%d", &num_of_test);
	double C = 0.0;
	double F = 0.0;
	double X = 0.0;
	double rate;
	double time_cost;
	for (int i = 1; i <= num_of_test; i++)
	{
		fscanf(f, "%lf %lf %lf", &C, &F, &X);
		rate = 2.0;
		time_cost = 0; 
		while (true)
		{
			if (X / rate <= (C / rate + X / (rate + F)))
			{
				time_cost += X / rate;
				//printf("%lf\n", time_cost);
				break;
			}
			else
			{
				time_cost += C / rate;
				//printf("%lf\n", time_cost);
				rate +=  F;
			}
		}
		fprintf(out, "Case #%d: %lf\n", i, time_cost);
	}
	fclose(f);
	fclose(out);
}