#include <stdio.h>
#include <string.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, n, s, p;
	int i, in, small, large;
	int full, half;
	int Case = 1;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &s, &p);
		full = 0;
		half = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &in);
			if (in == 0)
			{
				small = 0;
				large = 0;
			}
			else if (in == 1)
			{
				small = 1;
				large = 1;
			}
			else if (in == 3)
			{
				small = 1;
				large = 2;
			}
			else if (in%3 == 0)
			{
				small = in/3;
				large = small + 1;
			}
			else if (in%3 == 1)
			{
				small = in/3 + 1;
				large = small;
			}
			else
			{
				small = in/3 + 1;
				large = small + 1;
			}
			if(small >= p) full++;
			else if(small < p && large >= p) half++;
		}
		printf("Case #%d: %d\n", Case++, full+(half>s?s:half));
	}
}