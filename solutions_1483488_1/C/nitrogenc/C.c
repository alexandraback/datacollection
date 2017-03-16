#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	//Variables.
	int i, j, k, n, p, r, t;
	int minima, maxima;
	FILE *f_in, *f_out;
	if (!(f_in = fopen("C.in", "r")))
	{
		puts("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("C.out", "w+");
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d: ", i+1);
		fscanf(f_in, "%d %d", &minima, &maxima);
		//printf("Scanning from %d to %d.\n", minima, maxima);
		r = 0;
		p = 1;
		while (minima/p != 0) p*=10;
		p/=10;
		//printf("Power = %d\n", p);
		for(j = minima; j < maxima; j++)
		{
			//printf("Running: %d\n", j);
			t = 0;
			while (t != j)
			{
				if (t == 0)
				{
					t = (j/10)+(j%10)*p;
				}
				else
				{
					t = (t/10)+(t%10)*p;
				}
				if (t > j && t <= maxima)
				{
					//printf("Winners: (%d, %d)\n", j, t);
					r++;
				}
			}
			if ((j+1) == 10*p) p *= 10;
		}
		fprintf(f_out, "%d\n", r);
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
