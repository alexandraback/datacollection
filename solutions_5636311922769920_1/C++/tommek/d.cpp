#include <bits/stdc++.h>

using namespace std;

const int MX = 1005;

int main()
{
	int ttte; scanf("%d", &ttte); for (int ttt = 1; ttt <= ttte; ++ ttt)
	{	
		printf("Case #%d: ", ttt);
	
		int k, c, s; scanf("%d%d%d",&k, &c, &s);
		if (c == 1 || k == 1)
		{
			if (s == k)
			{
				for (int i = 1; i <= s; ++ i)
				{
					printf("%d ", i);
				}
				puts("");
			}
			else
			{
				puts("IMPOSSIBLE");
			}
		}
		else
		{
			if (s >= k-1)
			{
				for (int i = 2; i <= k; ++ i)
				{
					printf("%d ", i);
				}
				puts("");
			}	
			else
			{
				puts("IMPOSSIBLE");
			}
		}
	}
}
