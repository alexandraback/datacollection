#include <iostream>
#include <math.h>
#include <string.h>
#define N 1001
using namespace std;
double runs(double t,double v0,double a)
{
	return v0*t+a*t*t/2;
}
int main()
{
	freopen("B-small-attempt0(1).in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,t,cas,j,n,a;
	double d,ti[2001],xi[2001],ai,s0,v0,ans;
	ti[0]=xi[0]=0;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		scanf("%lf%d%d",&d,&n,&a);
		for(i=1;i<=n;i++)
			scanf("%lf%lf",ti+i,xi+i);
		printf("Case #%d:\n",cas);
		for(j=0;j<a;j++)
		{
			s0=v0=0;
			scanf("%lf",&ai);
			for(i=1;i<=n;i++)
			{
				
				if(runs(ti[i]-ti[i-1],v0,ai)+s0<xi[i])
				{
					if(xi[i]>=d)
					{
						ans=ti[i-1]+(sqrt(v0*v0+2*ai*(d-s0))-v0)/ai;
						break;
					}
					s0+=runs(ti[i]-ti[i-1],v0,ai);
					v0+=ai*(ti[i]-ti[i-1]);
				}
				else
				{
					if(xi[i]>=d)
					{
						ans=ti[i-1]+(sqrt(v0*v0+2*ai*(d-s0))-v0)/ai;
						if(ti[i]-ti[i-1]>1e-8)
						{
							if((d-xi[i-1])*(ti[i]-ti[i-1])/(xi[i]-xi[i-1])>ans)
								ans=(d-xi[i-1])*(ti[i]-ti[i-1])/(xi[i]-xi[i-1]);
						}
						break;
					}
					if(ti[i]-ti[i-1]<1e-8)v0=0;
					else v0=sqrt(2*(xi[i]-s0)/ai);
					s0=xi[i];
				}
			}
			printf("%.7lf\n",ans);
		}
	}
	return 0;
}