#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LN_LEN 1024

int getdoublearr(const char *str, double *arr, int n)
{
	const char *p = str;
	char *e;
	int i;
	for (i = 0; i < n; i++)
	{
		while (isspace(*p))
			p++;
		double v = strtod(p, &e);
		arr[i] = v;
		p = e + 1;
	}
	return i;
}

double solve(FILE *fin)
{
	char line[MAX_LN_LEN];
	if (!fgets(line, MAX_LN_LEN - 1, fin))
		return -1.0;
	double arr[3];
	getdoublearr(line, arr, 3);
	double c = arr[0];
	double f = arr[1];
	double x = arr[2];		
	double t0 = 0.0;
	double tc, tf;
	double r = 2.0;
	double t1 = x / r;
	double t;
	do
	{
		t = t1;
		tc = c / r;	
		r += f;
		tf = x / r;
		t0 += tc;
		t1 = t0 + tf;		
	}
	while (t1 < t);
	
	return t;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		return 1;
	}
	FILE *f = fopen(argv[1], "rt");
	if (f == NULL)
	{
		fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
		return 2;
	}
	FILE *out = stdout;
	if (argc > 2)
	{
		if ((out = fopen(argv[2], "wt")) == NULL)
		{
			fprintf(stderr, "Cannot open output file: %s\n", argv[2]);
			return 3;
		}
	}
	char line[MAX_LN_LEN];
	if (!fgets(line, MAX_LN_LEN - 1, f))
	{
		fprintf(stderr, "Empty input file: %s\n", argv[1]);
		return 4;
	}
	int n = atoi(line);
	if (n < 1)
	{
		fprintf(stderr, "Invalid input file: %s\n", argv[1]);
		return 5;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		double result = solve(f);
		fprintf(out, "Case #%d: %.7f\n", i + 1, result);		
			
	}
	fclose(f);
	if (out != stdout)
		fclose(out);
	return 0;
}
