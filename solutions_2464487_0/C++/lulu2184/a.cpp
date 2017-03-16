#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define sqr(x) ((x)*(x))
const double pi=acos(-1);

int T;
long long r,t;

bool check(long long x)
{
	long long ret=-t;
	ret+=x*r*2;
	ret+=(2*x-1)*x;
	if (ret<=0) return true;
	else return false;
}

bool cc(long double x)
{
	long double ret=-t;
	ret+=x*r*2;
	ret+=(2*x-1)*x;
	if (ret<1e-7) return true;
	else return false;
}

long double getans()
{
	long double left=1,right=t;
	while (right-left>1e-2)
	{
		long double mid=(left+right)/2;
		if (cc(mid)) left=mid;
		else right=mid;
	}
	return left;
}

int main()
{
	freopen("a.in","r",stdin);
	
	int TT=0;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%I64d%I64d",&r,&t);
		//long double delta=sqr(pi*((long double)r+r+1))+8*t*pi;
		long double ans1=getans();
		long long ans=floor(ans1);
		if (!check(ans))
		{
			for (;!check(ans);ans--);
		}else 
		{
			for (;check(ans);ans++);
			ans--;
		}
		printf("Case #%d: %I64d\n",++TT,ans);
	}
	
	return 0;
}