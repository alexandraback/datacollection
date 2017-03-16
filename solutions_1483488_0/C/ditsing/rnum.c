#include <stdio.h>
#include <stdlib.h>
#define MAXL 10

const int Bits[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int nums[MAXL];

int cmp( const void *a, const void *b)
{
	return *( const int *)b - *( const int *)a;
}

int main()
{
	int Tcases, A, B;
	int cases;
	scanf("%d", &Tcases);
	for ( cases = 0; cases < Tcases; cases++)
	{
		scanf("%d %d", &A, &B);
		int ans = 0;
		while ( A < B)
		{
			int cur = A;
			int L = 0;
			while ( Bits[L] <= cur)
			{
				++L;
			}

			--L;
			int u = L;
			int cnt = 0;
			while ( u--)
			{
				int last = cur % 10;
				cur /= 10;
				if ( last != 0)
				{
					cur += last * Bits[L];
					if ( cur > A && cur <= B)
					{
						nums[cnt++] = cur;
						++ans;
					}
				}
			}

			qsort( nums, cnt, sizeof( int), cmp);
			for ( u = 1; u < cnt; u++)
			{
				ans -= nums[u] == nums[u-1];
			}
			++A;
		}

		printf("Case #%d: %d\n", cases + 1, ans);
	}

	return 0;
}
