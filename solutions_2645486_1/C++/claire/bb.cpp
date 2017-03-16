#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N=10010;
LL v[N],f[N];

int main()
{
	LL o,e,r,n,i,j,x,y,k,cas=0,ans,now;
	scanf("%lld",&o);
	while (o--)
	{
		scanf("%lld%lld%lld",&e,&r,&n); r=min(r,e);
		for (i=1; i<=n; i++) scanf("%lld",&v[i]);
		for (i=1; i<=n; i++)
		{
			 for (j=i+1; j<=n; j++) if (v[j]>v[i]) break;
			 f[i]=j;
	    }
	    now=e;
	    ans=0;
	    for (i=1; i<=n; i++)
	    {
	    	if (f[i]>n) {ans+=now*v[i]; now=min(now-now+r,e); continue;}
	    	x=f[i];
	    	if (now+(x-i)*r<=e) now=min(now+r,e);
	    	else
	    	{
	    		y=now+(x-i)*r-e;
	    		y=min(now,y);
	    		ans+=y*v[i]; now=min(now-y+r,e);
	    	}
	    }
	    printf("Case #%lld: %lld\n",++cas,ans);
	}
}
