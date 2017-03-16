#include <cstdio>
#include <cmath>
#include <algorithm>
#define int64 long long

using namespace std;

int64 r,t;
int Test;

bool Check(int64 lim)
{
	if (2*lim*lim>t || t/lim<2*r-10) return false;
	return 2*lim*lim+lim*(r*2-1)<=t;
}

int main()
{
	freopen("A1.in","r",stdin);
	freopen("A.out","w",stdout);

	scanf("%d",&Test);
	for (int ii=0;ii<Test;++ii)
	{
		scanf("%I64d%I64d",&r,&t);
			
		int64 l=1,r=min((int64)sqrt(t)+10,(int64)t/(r*2-1)+10);
		for (;l<r;)
		{
			int64 mid=(l+r)/2+1;
			if (Check(mid)) l=mid;
			else r=mid-1;
		}

		printf("Case #%d: %I64d\n",ii+1,l);
	}

	return 0;
}
