#include<iostream>
#include<cmath>
using namespace std;
double f[2000][2];
double solve(double a,double b,double c)
{
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}
int main()
{
	double D,acce;
	int t,N,A;
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d:\n",i);
		scanf("%lf%d%d",&D,&N,&A);
		for(int j=0;j<N;j++)
			scanf("%lf%lf",&f[j][0],&f[j][1]);
		while(A--)
		{
			scanf("%lf",&acce);
			int j;
			for(j=N-1;j>=0;j--)
			{
				if(f[j][1]<=D)break;
			}
			double ans=sqrt(2*D/acce);
			double tmp;
			if(f[j][0]>ans)
			{
				ans=f[j][0];
				if(f[j][1]<D)
				{
					if(j+1<N)
					{
						tmp=(D-f[j][1])*(f[j+1][0]-f[j][0])/(f[j+1][1]-f[j][1]);
						double t1=sqrt(f[j][1]*2/acce);
						double v1=acce*t1;
						double t2=solve(acce/2.0,v1,f[j][1]-D);
						if(t2>tmp)tmp=t2;
						ans+=tmp;
					}
				}
			}
			else
			{
				if(f[j][1]<D)
				{
					if(j+1<N)
					{
						tmp=(D-f[j][1])*(f[j+1][0]-f[j][0])/(f[j+1][1]-f[j][1]);
						double t1=sqrt(f[j][1]*2/acce);
						double v1=acce*t1;
						double t2=solve(acce/2.0,v1,f[j][1]-D);
						if(t2>tmp)tmp=t2;
						ans=tmp+f[j][0];
					}
				}
			}
			printf("%.8lf\n",ans);
		}
	}
	return 0;
}