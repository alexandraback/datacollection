#include <stdio.h>

#define MAXN (128)

int T;
int R, C;

int B[MAXN][MAXN];

int main()
{
	int tt;
	scanf("%d", &T);
	for(tt = 1; tt <= T; ++tt)
	{
		int i, j, k;
		scanf("%d %d", &R, &C);

		for(i = 0; i < R; ++i)
		{
			for(j = 0; j < C; ++j)
			{
				scanf("%d", &B[i][j]);
			}
		}

		int yes = 1;
		for(i = 0; i < R && yes; ++i)
		{
			for(j = 0; j < C && yes; ++j)
			{
				int highrow = 0;
				int highcol = 0;

				for(k = 0; k < R; ++k)
				{
					if(k != i && B[k][j] > B[i][j])
					{
						highcol = 1;
						break;
					}
				}

				for(k = 0; k < C; ++k)
				{
					if(k != j && B[i][k] > B[i][j])
					{
						highrow = 1;
						break;
					}
				}

				if(highrow && highcol)
					yes = 0;
			}
		}

		printf("Case #%d: ", tt);
		if(yes)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
