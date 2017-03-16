#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int cl[1001][10];
int M[1001];
int hits[1001];
int prev[1001];

int search(int class, int from)
{
	if (hits[class] && prev[class] != from) return 1;
	hits[class]++;
	prev[class] = from;
	int i;
	for (i=0;i<M[class];i++)
	{
		if (search(cl[class][i], class)) return 1;
	}
	return 0;
}

int main(int argc, char**argv)
{
	if (argc != 2) exit(1);
	FILE *in = fopen(argv[1], "rt");
	FILE *out = fopen("out", "wt");
	if (!in || !out) {
		perror(NULL);
		exit(1);
	}
	int T=0;
	fscanf(in,"%d",&T);
	int tc,i,j;//,k,l,m,n;
	for (tc = 1; tc <= T; tc++) {
		int N;
		fscanf(in,"%d",&N);

		int found=0;

		for (i=1;i<=N;i++)
		{
			fscanf(in,"%d",M+i);
			for (j=0;j<M[i];j++)
			{
				fscanf(in,"%d",&cl[i][j]);
			}
		}

		for (i=1;i<=N;i++)
		{
			memset(hits, 0, sizeof hits);
			memset(prev, 0, sizeof prev);
			found=search(i,-1);
			if (found) break;
		}

		fprintf(out, "Case #%d: %s\n", tc, found?"Yes":"No");
	}
	fclose(in);
	fclose(out);
	return 0;
}
