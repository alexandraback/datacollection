#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[40], coin[10], c, v, d;

int main()
{
	int o, l;
	scanf("%d", &o);
	for(l = 1; l <= o; l++)
	{
		scanf("%d%d%d", &c, &d, &v);
		int i, j, sol = 0;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for(i = 0; i < d; i++)
			scanf("%d", &coin[i]);
		sort(coin, coin + d);
		for(i = 0; i < d; i++)
			for(j = 0; j < c; j++)
			{
				int t = coin[i], k = v;
				while(k - t >= 0)
				{
					dp[k] += dp[k - t];
					k--;
				}
			}		
		/*for(i = 1; i <= v; i++)
			printf("%d ", dp[i]);
		printf("\n");*/
		for(i = 1; i <= v; i++)
			if(!dp[i])
			{
			//	printf("%d\n", i);
				sol++;		
				for(j = 0; j < c; j++)
				{
					int k = v;
					while(k - i >= 0)
					{
						dp[k] += dp[k - i];
						k--;
					}
				}		
			/*	for(j = 1; j <= v; j++)
					printf("%d ", dp[j]);
				printf("\n");*/
			}
		/*for(i = 1; i <= v; i++)
			printf("%d\n", dp[i]);
		*/printf("Case #%d: %d\n", l, sol);
	}
	return 1;
}
