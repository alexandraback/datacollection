#include <cstdio>
int r, c, w;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++)
	{
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: ", tt);
		if (c % w == 0)
		{
			printf("%d\n", c / w - 1 + w);
		}
		else
		{
			printf("%d\n", c / w - 1 + w + 1);
		}
	}
	return 0;
}
