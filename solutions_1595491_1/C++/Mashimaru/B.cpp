#include <cstdio>
using namespace std;

int test, ans, n, s, p, t;

int main()
{
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	scanf("%d", &test);
	for (int num = 1; num <= test; num++)
	{
		scanf("%d %d %d", &n, &s, &p);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &t);
			int a = t / 3, b = t % 3;
			if (b == 0)
			{
				if (a >= p) ans++;
				else if (a && a + 1 >= p && s)
				{
					s--;
					ans++;
				}
			}
			else if (b == 1)
			{
				if (a + 1 >= p) ans++;
			}
			else
			{
				if (a + 1 >= p) ans++;
				else if (s && a + 2 >= p)
				{
					s--;
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", num, ans);
	}
	return 0;
}
