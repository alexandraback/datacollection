#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int num_case, cnt[10086], n, ans[100], len, u;

int main()
{
	freopen("B2.in", "r", stdin);
	freopen("B2.out", "w", stdout);
	scanf("%d", &num_case);
	for (int icase = 1; icase <= num_case; icase++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n - 1; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &u);
				cnt[u] ^= 1;
			}
		len = 0;
		for (int i = 1; i <= 2500; i++)
			if (cnt[i])
			{
				ans[++len] = i;
				cnt[i] = 0;
			}
		printf("Case #%d: ", icase);
		for (int i = 1; i < len; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[len]);
	}
	return 0;
}
