#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long LL;
const double pi=acos(-1.0);
const double eps=1e-7;

LL cal(LL k,LL dr,LL t)
{
	double s,n=k;
	s=2*n*(2*n-1)*(2*n+1)/6-4*(n-1)*n*(2*n-1)/6;
	s=2*(double)dr*(double)k+s;
	//cout<<k<<' '<<dr<<' '<<t<<' '<<s<<endl;
	if (s<(double)t+eps) return 1; else return 0;
}

LL bs(LL l,LL r,LL dr,LL t)
{
	LL res=0;
	while (l<=r)
	{
		LL mid=(l+r)/2;
		if (cal(mid,dr,t)==0) r=mid-1;
		else 
		{
			res=max(res,mid);
			l=mid+1;
		}
	}
	return res;
}

int main()
{
	int o,cas=0;
	LL r,t,ans;
	scanf("%d",&o);
	while (o--)
	{
		scanf("%lld%lld",&r,&t);
		ans=bs(0,t,r,t);
		printf("Case #%d: %lld\n",++cas,ans);
	}
}
