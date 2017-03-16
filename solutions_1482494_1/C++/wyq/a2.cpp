#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

typedef struct unit
{
	int index;
	int num;
} unit;
unit a[10000], b[10000];
int compare(const void *a1 , const void *a2);
int compare_deep(const void *a1 , const void *a2);


int main()
{
	FILE* infile = fopen("B-large.in", "r");
	FILE* outfile = fopen("out.txt", "w");

	int cases;
	int s[10000];
	int N, A, step, stars;
	int i, j;

	fscanf(infile, "%d\n", &cases);
	for(i = 0; i < cases; ++i)
	{
		fscanf(infile, "%d\n", &N);
		for(j = 0; j < N; ++j)
		{
			fscanf(infile, "%d %d\n", &(a[j].num), &(b[j].num));
			a[j].index = b[j].index = j;
			s[j] = 0;
		}
		A = step = stars = 0;
		qsort(a, N, sizeof(unit), compare_deep);
		qsort(b, N, sizeof(unit), compare);

		for(j = 0; j < N; ++j)
		{
			while(b[j].num > stars)
			{
				while(A < N && s[a[A].index])
				{
					++A;
				}
				if(A >= N || a[A].num > stars)
				{
					break;
				}
				else
				{
					++stars;
					++step;
					s[a[A].index] = 1;
					++A;
				}
			}
			if(b[j].num > stars)
			{
				break;
			}
			if(s[b[j].index])
				++stars;
			else
				stars += 2;
			s[b[j].index] = 2;
			++step;
		}
		if(j != N)
		{
			fprintf(outfile, "Case #%d: Too Bad\n", i + 1);
		}
		else
		{
			fprintf(outfile, "Case #%d: %d\n", i + 1, step);
		}
	}
	fclose(infile);
	fclose(outfile);

	return 0;
}

int compare(const void *a1 , const void *a2)
{
	return ((unit *)a1)->num - ((unit *)a2)->num;
}
int compare_deep(const void *a1 , const void *a2)
{
	if(((unit *)a1)->num - ((unit *)a2)->num)
	{
		return ((unit *)a1)->num - ((unit *)a2)->num;
	}
	else
	{
		return b[((unit *)a2)->index].num - b[((unit *)a1)->index].num;
	}
}