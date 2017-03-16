#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	freopen("c:\\temp\\a.in","r",stdin);
	freopen("c:\\temp\\a.out","w",stdout);
	scanf("%lld",&T);
	for (int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);
		unsigned long long r, t;
		scanf("%llu%llu",&r,&t);
		
		unsigned long long ans = 0;


		unsigned long long low = 1, hi = min(0x7FFFFFFFFFFFFFFFull / 2 / r, min(2147483647ull, t/(2*r+1)));

		while (low <= hi)
		{
			unsigned long long mid = (low + hi) / 2;
			if (2 * r * mid <= 0xFFFFFFFFFFFFFFFFull - 2 * mid * mid + mid && 2 * r * mid + 2 * mid * mid - mid <= t)
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