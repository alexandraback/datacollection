#include <stdio.h>
#include <math.h>

using namespace std;


int main()
{
	long long tc,t,r=0,k,n;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		scanf("%lld %lld",&r,&k);
		double rr=r;
		double kk=k;
		n=(sqrt(1+8.0*kk-4*rr+4*rr*rr)-2*rr-3)/4.0;
		if (n>0) --n;
		if (n>0) --n;
		while (1 + n + 2*n*(1 + n) + 2*(1 + n)*r <=k) ++n;
		printf("Case #%lld: %lld\n",tc+1,n);
	}
	return 0;
}
