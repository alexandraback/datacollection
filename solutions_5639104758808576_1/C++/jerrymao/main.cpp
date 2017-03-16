#include <bits/stdc++.h>

char s[1005];
int n;
int t;

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d%s", &n, s);
		int ans = 0, have = 0;
		for (int i = 0;i <= n;i++)
		{
			if (have < i) ans += (i-have), have=i;
			have += (s[i]-'0');
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
