#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n,x,y,T;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1; tt<=T; tt++)
	{
		scanf("%d%d%d",&n,&x,&y);
		x=abs(x); y=abs(y);
		printf("Case #%d: ",tt);
		int k=(x+y)/2;
		if (k==0 || 2*k*k+3*k+1<=n)
		{
			printf("1.0\n"); continue;
		}
		if (n<=2*k*k-k)
		{
			printf("0.0\n"); continue;
		}
		if (y==2*k)
		{
			printf("0.0\n"); continue;
		}
		double p=1;
		for (int i=0; i<y+1; i++)
			p/=2;
		double ans=0;
		if (y+1+2*k*k-k<=n)
			ans+=p;
		for (int i=1; i<=2*k; i++)
		{
			if (y+1+i+2*k*k-k>n)
				break;
			if (i==2*k)
			{
				ans=1; break;
			}
			p=p*double(y+i)/double(i);
			p/=2;
			ans+=p;
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}