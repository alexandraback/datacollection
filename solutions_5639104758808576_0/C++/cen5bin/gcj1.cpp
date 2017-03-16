#include <cstdio>
#include <cstring>
char s[1010];
int main()
{
	freopen("1in.txt", "r", stdin);
	freopen("1out.txt", "w", stdout);
	int n;
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		scanf("%d", &n);
		scanf("%s", s);
		int now = s[0] - '0';
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (now < i) 
			{
				ans += i - now;
				now = i;
			}
			now += s[i] - '0';
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
