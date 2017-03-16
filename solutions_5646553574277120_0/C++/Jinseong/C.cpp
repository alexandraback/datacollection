#include <stdio.h>
#include <stdlib.h>

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int cs = 1; cs <= T; cs++)
	{
		int ans = 0;
		int C, D, V;
		int all[110] = {0,};
		int cache[110] = {0,};
		int coins[110] = {0,};
		int ccnt = 0;

		scanf("%d %d %d", &C, &D, &V);
		

		
		for(int i = 1; i <= D; i++)
		{
			scanf("%d", &coins[i]);
			all[coins[i]] = 1;
			//cache[ccnt++] = coins[i];
		}

		for(int i = 1; i <= V; i++)
		{
			int cur = i;
			if(all[i] == 1)
			{
				continue;
			}
			for(int j = i-1; j != 0; j--)
			{
				if((all[j] == 0) || (j > cur))
				{
					continue;
				}
				cur -= j;


				if(cur == 0)
				{
					break;
				}
			}
			if(cur != 0)
			{
				//we need this num;
				all[i] = 1;
				ans++;
			}
		}

		
		printf("Case #%d: %d\n", cs, ans);
	}
	
}