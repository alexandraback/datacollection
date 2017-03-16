#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[110][110], r[110], c[110], n, m, T;

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	int ca = 0;
	while (T--)
	{
		ca++;
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				if (r[i] < a[i][j]) r[i] = a[i][j];
				if (c[j] < a[i][j]) c[j] = a[i][j];
			}
		bool flag = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] != min(r[i], c[j])) flag = false;
		if (flag)
			printf("Case #%d: YES\n", ca);
		else printf("Case #%d: NO\n", ca);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
