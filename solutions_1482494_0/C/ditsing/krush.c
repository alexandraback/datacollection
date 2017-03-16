#include <stdio.h>
#include <string.h>
#define MAXN 1000

int level[MAXN][2];
int flag[MAXN];

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		int N;
		scanf("%d", &N);
		int i;
		for ( i = 0; i < N; i++)
		{
			scanf("%d %d", level[i], level[i] + 1);
		}

		memset( flag, 0, sizeof( flag));
		int cur = 0;
		int cnt = 0;
		int ans = 0;
		while ( cnt != N && cnt != -1)
		{
			int next = -1;
			int score = 1;
			int lower = 1;
			for ( i = 0; i < N && next == -1; i++)
			{
				if ( flag[i] == 0 && level[i][1] <= cur)
				{
					next = i;
					score = 2;
				}
			}

			for ( i = 0; i < N && next == -1; i++)
			{
				if ( level[i][1] <= cur)
				{
					next = i;
				}
			}

			if ( next == -1)
			{
				for ( i = 0; i < N; i++)
				{
					if ( level[i][0] <= cur)
					{
						if ( next == -1 || ( level[i][1] >= level[next][1]))
						{
							next = i;
							lower = 0;
						}
					}
				}
			}

			if ( next != -1)
			{
				cnt += lower;
				cur += score;
				flag[next] |= lower;
				level[next][lower] = MAXN*MAXN;
			}
			else
			{
				cnt = -1;
			}
			++ans;
		}

		printf("Case #%d: ", cases + 1);
		if ( cnt == -1)
		{
			printf("Too Bad\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}

	return 0;
}
