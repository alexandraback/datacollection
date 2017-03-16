#include <bits/stdc++.h>

using namespace std;

int pancake[1111];

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ", ++TK);
		int D = 0;
		scanf("%d",&D);
		for(int i = 0;i < D;i++) scanf("%d",&pancake[i]);

		int ans = ~0U>>1;
		for(int i = 1;i <= 1000;i++)
		{
			int moveCost = 0;
			for(int j = 0;j < D;j++)
			{
				if(pancake[j] > i) moveCost += (pancake[j]-i + i-1) / i;
			}
			ans = min(ans, i + moveCost);
		}
		printf("%d\n", ans);
	}
	return 0;
}