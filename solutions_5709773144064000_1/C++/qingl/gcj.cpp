//freopen("A-small-attempt0.in","r",stdin);
//freopen("A-small-attempt0.out","w",stdout);
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef __int64 ll;
const int INF = 1000000007;
int a[5][5],b[5][5];
double c,f,X;
bool check(double t)
{
	double x=0.0,k=2,nv=0.0;
	while(x<t)
	{
		if(k*(t-x)+nv>=X)return true;
		if(nv>=c)
		{
			nv-=c;
			k+=f;
		}
		else
		{
			x+=(c-nv)/k;
			nv=0.0;
			k+=f;
		}
	}
	return false;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
	int T,i,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf",&c,&f,&X);
		double low=0.0,high=1e5,mid;
		while(high-low>1e-8)
		{
			mid=(high+low)/2;
			if(check(mid))high=mid;
			else low=mid;
		}
		printf("Case #%d: %.7lf\n",ca++,mid);
	}
	return 0;
}
