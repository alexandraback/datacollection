#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int oo = 1 << 29;
int T, A, n;
int a[200];

int main()
{
	scanf("%d",&T);
	for (int test = 1; test <= T; ++test)
	{
		scanf("%d%d",&A, &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d",&a[i]);
		sort(a + 1, a + n + 1);
		
		int ans = oo, now = 0;
		int i;
		for (i = 1; i <= n; ++i)
		{
			if (A > a[i])
			{
				A += a[i];
			} else
			{
				ans = min(ans, now + n - i + 1);
				if (A == 1) break;
				while (A <= a[i])
				{
					++now;
					A = A * 2 - 1;
				}
			}
		}
		if (i > n) ans = min(ans, now);
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
