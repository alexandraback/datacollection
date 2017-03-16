#include <stdio.h>

int main(void)
{
	int t, T, k, A, B, L;
	double p, D, N0, N, min;
	FILE *in, *out;
	
	in = fopen("input.txt", "rt");
	out = fopen("output.txt", "wt");
	
	fscanf(in, "%d", &T);
	for (t = 1; t <= T; t++)
	{
		fscanf(in, "%d %d", &A, &B);
		
		B -= A;
		min = (double)(A + B + 2);
		
		k = A;
		D = (double)(A + B + 1);
		N0 = (double)((2 * k + B + 1) + (A + B + 1));
		if ((N = N0 - D) < min) min = N;
		
		for (k--, N0 -= 2.0; k >= 0; k--, N0 -= 2.0)
		{
			fscanf(in, "%lf", &p);
			D *= p;
			if ((N = N0 - D) < min) min = N;
		}
		
		fprintf(out, "Case #%d: %.10f\n", t, min);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}