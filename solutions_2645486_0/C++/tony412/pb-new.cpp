#include <stdio.h>
#include <algorithm>

int v[20], r, n, e;

int dfs(int now, int ne, int sum)
{
	if (now >= n) return sum;
	int ret = 0;

	for (int i = 0; i <= ne; i++)
		ret = std::max(ret, dfs(now+1, std::min(ne-i+r, e), sum+i*v[now]));
	return ret;
}

int main()
{
	int t, c = 1;
	int i, j;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &e, &r, &n);
		for (i = 0; i < n; i++)
			scanf("%d", &v[i]);
		printf("Case #%d: %d\n", c++, dfs(0, e, 0));
	}
	return 0;
}
