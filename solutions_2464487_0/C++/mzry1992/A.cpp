#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long R, T;

int main()
{
	int totCase;
	scanf("%d", &totCase);
	for (int cas = 1; cas <= totCase; cas++)
	{
		scanf("%lld%lld", &R, &T);
		long long l = 0, r = 1000000000, mid;
		while (l < r)
		{
			mid = (l + r + 1) >> 1;
			double _tot = (double)R * 2 + (double) mid * 2 + 1;
			_tot = _tot * (mid + 1);
			long long tot;
			if (_tot > 2e18)
				tot = 0x7fffffffffffffffLL;
			else
				tot = (R * 2 + mid * 2 + 1) * (mid + 1); 
//			printf("mid = %lld, tot = %lld, T = %lld\n", mid, tot, T);
			if (tot <= T)
				l = mid;
			else
				r = mid - 1;
		}
		printf("Case #%d: %lld\n", cas, l + 1);
	}
	return 0;
}

