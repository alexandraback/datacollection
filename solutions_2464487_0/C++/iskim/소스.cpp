#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	freopen("c:\\temp\\a.in","r",stdin);
	freopen("c:\\temp\\a.out","w",stdout);
	scanf("%d",&T);
	for (int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);
		long long r, t;
		scanf("%lld%lld",&r,&t);
		
		long long ans = 0;

		long long low = 1, hi = t/(2*r+1);

		while (low <= hi)
		{
			long long mid = (low + hi) / 2;
			if (2 * r * mid + 2 * mid * mid - mid <= t)
			{
				ans = max(ans, mid);
				low = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}