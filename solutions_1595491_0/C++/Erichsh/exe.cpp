#include <cstdio>

int main ()
{
	//freopen("data.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int n, s, p;	scanf("%d%d%d", &n, &s, &p);		
		int ans = 0, cnt = 0;
		while (n--)
		{
			int tem;	scanf("%d", &tem);
			if (p == 0)	ans ++;
			else if (p == 1)	
			{
				if (tem >= 1)	ans ++;
			}
			else
			{
				if (tem >= p + p-1 + p-1)		ans++;
				else if((tem == p + p-1 + p-2  || tem == p + p-2 + p-2 ) && s > 0)
					ans++, s--;
			}
		}
		printf("Case #%d: %d\n", tc, ans);
	}
}