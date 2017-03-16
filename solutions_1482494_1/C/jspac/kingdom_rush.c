#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
	int level;
	int requires1;
	int requires2;
} STAR;

int starcmp1(const void *p1, const void *p2)
{
	STAR s1 = *(STAR *)p1, s2 = *(STAR *)p2;
	return s1.requires1 <= s2.requires1 ? (s1.requires1 < s2.requires1 ? -1 : (s1.requires2 >= s2.requires2 ? (s1.requires2 > s2.requires2 ? -1 : 0) : 1)) : 1;
}

int starcmp2(const void *p1, const void *p2)
{
	STAR s1 = *(STAR *)p1, s2 = *(STAR *)p2;
	return s1.requires2 <= s2.requires2 ? (s1.requires2 < s2.requires2 ? -1 : (s1.requires1 >= s2.requires1 ? (s1.requires1 > s2.requires1 ? -1 : 0) : 1)) : 1;
}

int main(void)
{
	int t, T, n, N, cnt, ind1, earned, *completed[3];
	FILE *in, *out;
	STAR *list[3];
	
	list[1] = (STAR *)malloc(MAX * sizeof(STAR));
	list[2] = (STAR *)malloc(MAX * sizeof(STAR));
	completed[1] = (int *)malloc(MAX * sizeof(int));
	completed[2] = (int *)malloc(MAX * sizeof(int));
	
	in = fopen("input.txt", "rt");
	out = fopen("output.txt", "wt");
	
	fscanf(in, "%d", &T);
	for (t = 1; t <= T; t++)
	{
		fscanf(in, "%d", &N);
		for (n = 0; n < N; n++)
		{
			list[1][n].level = n;
			fscanf(in, "%d %d", &list[1][n].requires1, &list[1][n].requires2);
			list[2][n] = list[1][n];
		}
		qsort((void *)(list[1]), N, sizeof(STAR), starcmp1);
		qsort((void *)(list[2]), N, sizeof(STAR), starcmp2);
		
		cnt = ind1 = earned = 0;
		memset((void *)(completed[1]), 0, N * sizeof(int));
		memset((void *)(completed[2]), 0, N * sizeof(int));
		for (n = 0; n < N; n++)
		{
			if (earned >= list[2][n].requires2)
			{
				cnt++;
				earned += completed[1][list[2][n].level] ? 1 : 2;
				completed[2][list[2][n].level] = 1;
			}
			else
			{
				while (ind1 < N && earned >= list[1][ind1].requires1 && earned < list[2][n].requires2)
				{
					if (!completed[1][list[1][ind1].level] && !completed[2][list[1][ind1].level])
					{
						cnt++;
						earned++;
						completed[1][list[1][ind1].level] = 1;
					}
					ind1++;
				}
				if (earned < list[2][n].requires2) break;
				else
				{
					cnt++;
					earned += completed[1][list[2][n].level] ? 1 : 2;
					completed[2][list[2][n].level] = 1;
				}
			}
		}
		
		fprintf(out, "Case #%d: ", t);
		if (n < N) fprintf(out, "Too Bad\n");
		else fprintf(out, "%d\n", cnt);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}