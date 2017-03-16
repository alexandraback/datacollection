#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <float.h>
#include <limits.h>

void jh_open_io(int argc, char* argv[], FILE **fi, FILE **fo)
{
	assert(argc == 3);
	if(strcmp(argv[1], "stdin") == 0)
		*fi = stdin;
	else
		assert(*fi = fopen(argv[1], "r"));
	if(strcmp(argv[2], "stdout") == 0)
		*fo = stdout;
	else
		assert(*fo = fopen(argv[2], "w"));
}

void jh_close_io(FILE *fi, FILE *fo)
{
	fclose(fi);
	fclose(fo);
}

int cmp(const void *a, const void *b)
{
	if(*((double *)a) > *((double *)b))
		return 1;
	else if(*((double *)a) < *((double *)b))
		return -1;
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *fi, *fo;
	jh_open_io(argc, argv, &fi, &fo);

	int T;
	fscanf(fi, "%d\n", &T);

	int N, x, s[201];
	double p, p0, xx, d[201];
	for(int i = 1; i <= T; ++i)
	{
		fscanf(fi, "%d ", &N);
		fprintf(fo, "Case #%d: ", i);
		x = 0;
		for(int j = 1; j <= N; ++j)
		{
			fscanf(fi, "%d ", s + j);
			x += s[j];
		}
		for(int j = 1; j <= N; ++j)
		{
			p0 = p = 1;
			xx = 0;
			for(int k = 1; k <= N; ++k)
			{
				d[k] = ((double)(s[k] - s[j])) / x;
				xx += d[k];
			}
			qsort(d+1, N, sizeof(double), cmp);
			p0 = 1;
			for(int k = N; k >= 1; --k)
			{
				p = (xx + 1) / k;
				if(p < d[k])
				{
					xx -= d[k];
					continue;
				}
				p0 = p;
				break;
			}
			fprintf(fo, "%lf ", p0 < 0 ? 0 : p0 * 100);
		}
		fputc('\n', fo);

	}

	jh_close_io(fi, fo);
	return 0;
}