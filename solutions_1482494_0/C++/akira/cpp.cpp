#include <stdio.h>
#include <stdlib.h>
#define TOO_BAD 0x7fffffff
struct U
{
	int index;
	int num;
};
struct U a[1024], b[1024];
int cmp(const void *a1 , const void *a2)
{
	return ((U *)a1)->num - ((U *)a2)->num;
}
int cmp_a(const void *a1 , const void *a2)
{
	if(((U *)a1)->num - ((U *)a2)->num)
		return ((U *)a1)->num - ((U *)a2)->num;
	else
		return b[((U *)a2)->index].num - b[((U *)a1)->index].num;
}
void main()
{
	FILE* fi = fopen("C:\\t\\in.txt", "r");
	FILE* fo = fopen("C:\\t\\out.txt", "w");
	int T;
	int s[1024];
	int N, A, Times, Stars;
	int j;
	fscanf(fi, "%d\n", &T);
	for(int i = 0; i != T; ++i)
	{
		fscanf(fi, "%d\n", &N);
		for(j = 0; j != N; ++j)
		{
			fscanf(fi, "%d %d\n", &(a[j].num), &(b[j].num));
			a[j].index = b[j].index = j;
			s[j] = 0;
		}
		A = Times = Stars = 0;
		qsort(a, N, sizeof(U), cmp_a);
		qsort(b, N, sizeof(U), cmp);
		for(j = 0; j != N; ++j)
		{
			while(b[j].num > Stars)
			{
				while(A < N && s[a[A].index])
					++A;
				if(A >= N || a[A].num > Stars)
					break;
				else
				{
					++Stars;
					++Times;
					s[a[A].index] = 1;
					++A;
				}
			}
			if(b[j].num > Stars)
				break;
			if(s[b[j].index])
				++Stars;
			else
				Stars += 2;
			s[b[j].index] = 2;
			++Times;
		}
		if(j != N)
			fprintf(fo, "Case #%d: Too Bad\n", i + 1);
		else
			fprintf(fo, "Case #%d: %d\n", i + 1, Times);
	}
	fclose(fi);
	fclose(fo);
}