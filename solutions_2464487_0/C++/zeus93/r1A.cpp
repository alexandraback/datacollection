#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
unsigned long long val, ri;
unsigned long long sea(unsigned long long l,unsigned long long r)
{
	unsigned long long ans, mid;
	unsigned long long t;
	while(l <= r)
	{
		mid = (r + l) / 2;
		t = 2 * mid * mid + 2 * mid * ri - mid;
		if(t == val)
			return mid;
		if(t < val)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ans;
}
int main()
{
	int tcase, icase = 1;
	scanf("%d", &tcase);
	while(tcase--)
	{
		scanf("%lld%lld", &ri, &val);
		unsigned long long r = (unsigned long long)sqrt(val/2.0);
		printf("Case #%d: %lld\n",icase++, sea(1, r));
	}
	return 0;
}
