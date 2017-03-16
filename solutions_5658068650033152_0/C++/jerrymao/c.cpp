#include <cstdio>

int ans;
int n;
int m;
int k;
int t;

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d%d%d", &n, &m, &k);
		ans = k;
		for (int i = 3;i <= n;i++) for (int j = 3;j <= m;j++)
		{
			int alt = 2*(i-2)+2*(j-2);
			if (i*j-4 < k)
				alt += (k - (i*j - 4));
			if (alt < ans)
				ans = alt;
		}
		for (int i = 3;i <= n;i++) for (int j = 3;j <= m;j++)
		{
			int alt = i*2 + j*2;
			if (i*j < k)
				alt += (k - i*j);
			if (alt < ans)
				ans = alt;
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
