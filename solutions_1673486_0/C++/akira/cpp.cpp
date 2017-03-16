#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* fi = fopen("C:\\t\\in.txt", "r");
	FILE* fo = fopen("C:\\t\\out.txt", "w");
	int T, A, B;
	double p[100000];
	double min, s, ss;
	fscanf(fi, "%d\n", &T);
	for(int i = 0; i != T; ++i)
	{
		fscanf(fi, "%d %d\n", &A, &B);
		min = 1000000;
		s = 1;
		for(int j = 0; j != A; ++j)
		{
			fscanf(fi, "%lf ", p + j);
			p[j] *= s;
			s = p[j];
			ss = 2 * (A - j - 1) + B - A + 1 + (1 - p[j]) * (B + 1);
			if(ss < min)
				min = ss;
		}
		ss = B + 2;
		if(ss < min)
			min = ss;
		fprintf(fo, "Case #%d: %.6lf\n", i + 1, min);
	}
	fclose(fi);
	fclose(fo);
}