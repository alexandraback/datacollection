#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int a[1005];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; tt++)
	{
		int st, n;
		scanf("%d%d", &st, &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		sort(a, a + n);
		int cur = st, cn = 0;
		int ans = n;
		for(int i = 0; i < n; i++)
		{
			if(cur > a[i])
				cur += a[i];
			else
			{
				if(cur - 1 == 0)
					break;
				while(cur <= a[i])
					cur += (cur - 1), cn++;
				cur += a[i];
			}
			ans = min(ans, cn + (n - i - 1));
		}
		printf("Case #%d: %d\n", tt + 1, ans);
	}


	return 0;
}