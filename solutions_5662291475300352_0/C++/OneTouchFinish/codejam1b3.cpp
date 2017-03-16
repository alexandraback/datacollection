#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	ll t,ind,i,d[2],h,m[2],j,hh,n;
	getlong(t);
	rep(ind,1,t)
	{
		getlong(n);
		int cr=0;
		rep(j,1,n)
		{
			getlong(d[cr]);
			getlong(h);
			getlong(m[cr]);
			cr++;
			if(h==2)
			{
				d[cr]=d[cr-1];
				m[cr]=m[cr-1]+1;
				cr++;
			}
		}
		printf("Case #%lld: ",ind);
		if(cr==1)
		{
			putintln(0);
			continue;
		}
		if(d[0]>d[1])
		{
			swap(d[0],d[1]);
			swap(m[0],m[1]);
		}
		int res=0;
		if(m[0]>m[1])
		{
			double dd=360-d[0];
			dd/=m[1];
			dd*=m[0];
			dd+=d[1];
			if(dd>=720)
				res=1;
		}
		else if(m[1]>m[0])
		{
			double dd=360-d[0];
			dd/=m[0];
			dd*=m[1];
			dd+=d[1];
			if(dd>=720)
				res=1;
		}
		putintln(res);
	}	
}