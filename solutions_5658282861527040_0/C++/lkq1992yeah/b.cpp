#include <stdio.h>
#include <string.h>

int main()
{
	int t, cas;
	int a, b, k;
	int i, j;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		int cnt = 0;
		scanf("%d%d%d", &a, &b, &k);
		for (i = 0; i < a; i++)
		{
			for (j = 0; j < b; j++)
			{
				if ((i&j)<k)
					cnt++;
			}
		}
		printf("Case #%d: %d\n", cas, cnt);
	}
	return 0;
}
