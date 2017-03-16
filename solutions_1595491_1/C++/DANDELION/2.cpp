#include<stdio.h>

int main()
{
	int cas;
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int s, p, n;
	int t[101];
	scanf("%d", &cas);
	for(int idx = 1; idx <= cas; idx++)
	{
		int ans = 0;
		scanf("%d%d%d",&n, &s, &p);
		for(int i = 0; i < n; i++)
			scanf("%d", &t[i]);
		int val = p + (p - 2 > 0 ? p - 2 : 0) * 2;
		int val1 = p + (p - 1 > 0 ? p - 1 : 0) * 2;
		for(int i = 0; i < n; i++)
		{
			if (s && t[i] >= val && t[i] < val1)
			{
				s--;
				ans++;
			}else
			{
				if (t[i] >= val1)
					ans++;
			}
		}
		printf("Case #%d: %d\n", idx, ans);
	}
}