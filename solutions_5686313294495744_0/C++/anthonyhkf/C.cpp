#include <bits/stdc++.h>

using namespace std;

char a[1010][30], b[1010][30];
int n;

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s %s", a[i], b[i]);
		}
		int ans = 0;
		for (int i = (1 << n) - 1; i >= 0; --i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
			{
				if (!(i & (1 << j)))
				{
					// maybe faked

					bool found = false;
					for (int k = 0; !found && k < n; ++k)
						if (i & (1 << k))
						{
							if (strcmp(a[k], a[j])) continue;
							for (int l = 0; !found && l < n; ++l)
							{
								if (i & (1 << l))
								{
									if (strcmp(b[l], b[j])) continue;
									found = true;
								}
							}
						}
					if (found)
					{
						++cnt;
					}
				}
			}
			ans = max(ans, cnt);
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}