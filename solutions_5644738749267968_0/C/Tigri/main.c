#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LN_LEN 16384
#define MAX_N 1000

int ircmp(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b) 
		return 1;
	if (*(int*)a < *(int*)b) 
		return -1;
	return 0;
}

int getarr(const char *str, int *arr, int n)
{
	const char *p = str;
	int i;
	int k;
	int v;
	for (i = 0; i < n; i++)
	{
		while (isspace(*p))
			p++;
		if (p[0] != '0' || p[1] != '.')
			return -1;
		p += 2;
		v = 0;
		k = 0;
		while (isdigit(p[k]))
		{
			v = v * 10 + (p[k] - '0');
			k++;
		}
		if ((k < 1) || (k > 5))
			return -1;
		p += k;
		while (k < 5)
		{
			v *= 10;
			k++;
		}
		arr[i] = v;		
	}
	qsort(arr, n, sizeof(int), ircmp);
	fprintf(stderr, "[");
	for (i = 0; i < n; i++)
		fprintf(stderr, " %d%c", arr[i], (i == (n - 1)) ? ' ' : ',');
	fprintf(stderr, "]\n");
	return n;
}

int solve(FILE *fin, int *pd, int *pw)
{
	static char line[MAX_LN_LEN];
	if (!fgets(line, MAX_LN_LEN - 1, fin))
		return 0;
	int n = atoi(line);
	if (n < 1)
		return 0;
	fprintf(stderr, "(%d)\n", n);
	static int nblocks[MAX_N];
	static int kblocks[MAX_N];
	if (!fgets(line, MAX_LN_LEN - 1, fin))
		return 0;
	if (getarr(line, nblocks, n) < n)
		return 0;
	if (!fgets(line, MAX_LN_LEN - 1, fin))
		return 0;
	if (getarr(line, kblocks, n) < n)
		return 0;
	int w = n;
	int in = 0;
	int ik = 0;
	int sn = 0;	
	
	while (ik < n)
	{
		while (in < n && nblocks[in] < kblocks[ik])
		{
			in++;
			sn++;
		}
		while (ik < n && ((in >= n) || (nblocks[in] > kblocks[ik])))
		{
			if (sn > 0)
			{
				sn--;
				w--;
			}
			ik++;
		}
	}
	int d = 0;
	int ic = 0;
	in = n - 1;
	ik = n - 1;
	while ((in - ic) >= 0)
	{
		while (((in - ic) >= 0) && (ik >= 0) && (kblocks[ik] > nblocks[in]))
		{
			ic++;
			ik--;
		}
		while (((in - ic) >= 0) && ((ik < 0) || (kblocks[ik] < nblocks[in])))
		{
			if (ik >= 0)
			{
				ik--;
				d++;
			}
			in--;
		}
	}
	*pw = w;
	*pd = d;
	return 1;
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
	int d, w;
	for (i = 0; i < n; i++)
	{
		if (!solve(f, &d, &w))
		{
			fprintf(stderr, "Invalid input file: %s\n", argv[1]);
			return 6;
		}
		fprintf(out, "Case #%d: %d %d\n", i + 1, d, w);			
	}
	fclose(f);
	if (out != stdout)
		fclose(out);
	return 0;
}
