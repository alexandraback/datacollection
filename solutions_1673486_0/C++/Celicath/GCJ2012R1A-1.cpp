#include<stdio.h>


int main()
{
	int T;

	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt","w");

	fscanf(fin, "%d\n", &T);

	for(int i = 1; i <= T; i++)
	{
		double prob = 1.0;

		int A, B;
		fscanf(fin, "%d%d\n", &A, &B);

		double result = 2 + B;

		for(int j = 1; j <= A; j++)
		{
			double temp;
			fscanf(fin, "%lf", &temp);
			prob *= temp;
			double now = (A+B-2*j+1) + (B+1) * (1-prob);
			if(now < result)result = now;
		}

		fprintf(fout,"Case #%d: %f\n", i, result);
	}
	return 0;
}
