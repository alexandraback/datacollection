#include <stdio.h>
#include <stdlib.h>

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int cs = 1; cs <= T; cs++)
	{
		int ans = 0;
		int R, C, W;
		scanf("%d %d %d", &R, &C, &W);

		if(W == 1)
		{
			ans = R*C;
		}
		else
		{
			for(int i = 0; i < R; i++)
			{
				for(int j = 1; j <= C/W; j++)
				{
					int pos = (j*W) -1;
					ans++;
				}
			}
			ans += (W-1);
			if(C % W != 0)
			{
				ans++;
			}
		}
		printf("Case #%d: %d\n", cs, ans);
	}
	
}