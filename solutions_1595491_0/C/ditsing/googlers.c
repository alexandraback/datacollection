#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define MAX( a, b) ( ( a) > ( b) ? ( a) : ( b))

int nums[MAXN];
int T;
int N, S, P;

int cmp( const void *a, const void *b)
{
	return *( const int *)b - *( const int *)a;
}

int main()
{
	scanf("%d", &T);
	int cases;
	for ( cases = 0; cases < T; cases++)
	{
		scanf("%d %d %d", &N, &S, &P);
		int i;
		for ( i = 0; i < N; i++)
		{
			scanf("%d", nums + i);
		}
		
		qsort( nums, N, sizeof( int), cmp);

		int ans = 0;
		for ( i = 0; i < N; i++)
		{
			int u, v;
			int max = -1, use = -1;
			for ( u = 2; u >= 0; u--)
			{
				for ( v = u; v >= 0; v--)
				{
					int cur = nums[i] - u - v;
					if ( cur >= 0 && cur % 3 == 0)
					{
//						printf("here %d %d %d %d\n", u, v, nums[i], cur);
						cur /= 3;
						if ( u == 2)
						{
							use = MAX( use, cur + 2);
						}
						else
						{
							max = MAX( max, cur + u);
						}
					}
				}
			}

//			printf("%d %d %d %d\n", nums[i], max, use, P);
			if ( max >= P)
			{
				++ans;
			}
			else
			{
				if ( S > 0 && use >= P)
				{
					++ans, --S;
				}
			}
		}

		printf("Case #%d: %d\n", cases + 1, ans);
	}

	return 0;
}
