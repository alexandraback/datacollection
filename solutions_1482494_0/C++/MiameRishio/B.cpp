#include <iostream>

const int maxn = 1005;
int a[maxn][2];
int b[maxn];
int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int testCase;
	scanf("%d", &testCase);
	for (int te = 1; te <= testCase; te++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i][0], &a[i][1]);

		bool bUpdate = true;
		int stars = 0;
		for (int i = 0; i < n; i++)
			b[i] = 0;
		int ans = 0;
		while (bUpdate)
		{
			bUpdate = false;
			for (int i = 0; i < n; i++)
				if (stars >= a[i][1] && b[i] != 2)
				{
					bUpdate = true;
					stars += 2 - b[i];
					ans++;
					b[i] = 2;
				}

			if (!bUpdate)
			{
				int tmp = -1;
				for (int i = 0; i < n; i++)
					if (b[i] == 0 && stars >= a[i][0])
						if (tmp == -1 || a[tmp][0] < a[i][0])
						tmp = i;

				if (tmp != -1)
				{
					bUpdate = true;
					b[tmp] = 1;
					stars += 1;
					ans++;
				}
			}
		}
		if (stars == 2 * n)
			printf("Case #%d: %d\n", te, ans);
		else
			printf("Case #%d: Too Bad\n", te);
	}
	return 0;
}
