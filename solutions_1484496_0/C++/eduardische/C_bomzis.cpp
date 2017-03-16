#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 25

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int data[MAXN];
	static int b[3000000]; //CHECK THIS!!!!!
	for (iT = 0; iT < T; iT++)
	{
		printf("Case #%d:\n",iT+1);
		int i, N;
		scanf("%d",&N);
		int resA, resB;
		resA = -1; resB = -1;
		for (i = 0; i < N; i++) scanf("%d",&(data[i]));
		int total = 1 << N;
		memset(b,0,sizeof(b));
		int j, nj, k;
		for (j = 1; j < total; j++)
		{
			nj = j;
			int S = 0;
			for (k = 0; k < N; k++)
			{
				if (nj % 2) S += data[k];
				nj /= 2;
			}
			if (b[S] == 0) b[S] = j;
			else
			{
				resA = b[S];
				resB = j;
				break;
			}
		}
		if (resA == -1) printf("Impossible\n");
		else
		{
			char first;

			first = 1;
			nj = resA;
			for (k = 0; k < N; k++)
			{
				if (nj % 2)
				{
					if (first) first = 0;
					else printf(" ");
					printf("%d",data[k]);
				}
				nj /= 2;
			}
			printf("\n");

			first = 1;
			nj = resB;
			for (k = 0; k < N; k++)
			{
				if (nj % 2)
				{
					if (first) first = 0;
					else printf(" ");
					printf("%d",data[k]);
				}
				nj /= 2;
			}
			printf("\n");
		}
	}
	return 0;
}
