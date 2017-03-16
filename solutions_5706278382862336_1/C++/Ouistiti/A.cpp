#include <cstdio>
#include <algorithm>

using namespace std;

long long p,q;

long long gcd (long long x,long long y)
{
	if (y>x)
		swap (x,y);
	if (x%y==0)
		return y;
	return gcd (y,x%y);
}

int main ()
{
	freopen ("A-large.in","r",stdin);
	freopen ("A-large.out","w",stdout);
	int ans,t,check;
	scanf ("%d",&t);
	for (int g=1;g<=t;g++)
	{
		ans = 1; check = 1;
		scanf ("%lld/%lld",&p,&q);
		long long k = gcd (p,q);
		p/=k; q/=k;
		while (q>1)
		{
			//printf ("%lld %lld\n",p,q);
			if (q%2==1)
				check = 0;
			if (p*2<q)
				ans++;
			q/=2;
		}
		printf ("Case #%d: ",g);
		if (check) printf ("%d\n",ans);
		else printf ("impossible\n");
	}
}
