#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 105
#define MYINF 1000000000

using namespace std;

int main ()
{
	static int a[MAXN][MAXN];
	int T, iT;
	scanf("%d",&T);
	static int score[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N, S, P;
		scanf("%d %d %d",&N,&S,&P);
		int i, j, k;
		for (i = 0; i < N; i++) scanf("%d",&(score[i]));
		for (i = 0; i <= N; i++)
		{
			for (j = 0; j <= N; j++)
			{
				a[i][j] = -MYINF;
			}
		}
		a[0][0] = 0;
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j <= N; j++)
			{
				int nval;
				if (j > 0)
				{
					nval = a[i-1][j-1];
					char flag = 0;
					int third;
					for (k = P; k <= 10; k++)
					{
						if (k >= 2)
						{
							third = score[i-1] - k - (k-2);
							if ((third >= (k-2)) && (third <= k)) flag = 1;
						}
					}
					if (flag) nval++;
					if ((nval >= 0) && (nval > a[i][j])) a[i][j] = nval;
				}
				nval = a[i-1][j];
				if (((score[i-1]+2)/3) >= P) nval++;
				if ((nval >= 0) && (nval > a[i][j])) a[i][j] = nval;
			}
		}
		printf("Case #%d: %d\n",iT+1,a[N][S]);
	}
}
