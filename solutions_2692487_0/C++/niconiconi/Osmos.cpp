#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		int sum, n;
		scanf("%d%d", &sum, &n);
		for(int j = 0; j < n; ++j) scanf("%d", a + j);
		sort(a, a + n);
		int cur = 0, curop = 0;
		int ans = 1000000000;
		for(; cur < n; ++cur)
		{
			if(a[cur] < sum) sum += a[cur];
			else
			{
				ans = min(ans, curop + n - cur);
				while(sum <= a[cur])
				{
					if(sum - 1 <= 0)
					{
						curop = 1000000000;
						break;
					}
					curop++, sum += sum - 1;
				}
				sum += a[cur];
			}
		}
		if(ans == 1000000000) ans = 0;
		ans = min(ans, curop);
		printf("Case #%d: %d\n", i, ans);
	}
	fclose(stdout);
	return 0;
}