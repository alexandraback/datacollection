#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", kase);
		if (n == 0)
			puts("INSOMNIA");
		else
		{
			long long cur = 0;
			bool vis[10];
			for (int i = 0; i < 10; ++i)
				vis[i] = 0;
			int cnt = 10;
			while (cnt)
			{
				cur += n;
				long long tmp = cur;
				while (tmp)
				{
					int d = tmp % 10;
					if (!vis[d])
					{
						vis[d] = 1;
						cnt--;
					}
					tmp /= 10;
				}
			}
			printf("%d\n", cur);
		}
	}
	return 0;
}
