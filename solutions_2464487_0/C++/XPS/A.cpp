#include<stdio.h>

int main()
{
	FILE *fin, *fout;
	int T;
	long long int r,t;
	int i;
	long long int min, max, n;

	fin = fopen("in.txt","r");
	fout = fopen("out.txt","w");
	fscanf(fin, "%d",&T);
	for(i = 0 ; i < T ; i++)
	{
		fscanf(fin, "%lld %lld", &r, &t);
		n = 1;
		while(t > (n * (2 * r + 2 * n - 1)))
			n *= 2;
		min = n / 2; max = n;
		while(!(t >= (n * (2 * r + 2 * n - 1)) &&
			t < ((n + 1) * (2 * r + 2 * (n + 1) - 1))))
		{
			n = (min + max) / 2;
			if( t < (n * (2 * r + 2 * n - 1)))
				max = n;
			else
				min = n;
		}
		fprintf(fout, "Case #%d: %lld\n", i+1, n);
	}
	return 0;
}