#include <stdio.h>


int main()
{
	int T, C;
	int a, b, k, i, j;
	int ans;
	
	scanf("%d", &T);
	for (C = 1; C <= T; C++)
	{
		scanf("%d %d %d", &a, &b, &k);
		ans = 0;
		for (i = 0; i < a; i++)
			for (j = 0; j < b; j++)
			{
				if ((i & j) < k)
					ans++;
			}
		printf("Case #%d: ", C);
		printf("%d\n", ans);
	}
	return 0;
}
