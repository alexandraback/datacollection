#include <stdio.h>

using namespace std;


int main()
{
	long long tc,t,r=0,p,q;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		scanf("%lld/%lld",&p,&q);
		int ok=1,x=0;
		while (p<q)
		{
			if (q&1)
			{
				ok=0;
				break;
			}
			q>>=1;
			++x;
		}
		if (x>40) ok=0;
		if (q&(~p)) ok=0;
		if (ok)
		{
			printf("Case #%lld: %d\n",tc+1,x);
		} else
		{
			printf("Case #%lld: impossible\n",tc+1);
		}
	}
	return 0;
}
