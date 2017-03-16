#include <iostream>
#include <stdio.h>
using namespace std;

long double d;
long double n,a;

long double t[2005];
long double p[2005];

long double acc[300];
long double speed[2005];


int main()
{
	int tt;
	int n;
	cin>>tt;
	for (int i=1;i<=tt;i++)
	{
		cin>>d>>n>>a;
		for (int j=0;j<n;j++)
		{
			cin>>t[j]>>p[j];
		}
		for (int j=0;j<a;j++)
		{
			cin>>acc[j];
		}
		for (int j=1;j<n;j++)
		{
			speed[j]=(p[j]-p[j-1])/(t[j]-t[j-1]);
		}
		printf("Case #%d:\n",i);
		long double curspeed=0;
		long double curpos=0;
		long double curt=0;
		long double res=0;
		for (int j=0;j<a;j++)
		{
			curspeed=0;
			curpos=0;
			curt=0;
			res=0;
			if (p[0]>=d)
			{
				long double et2=(-curspeed+sqrt(curspeed*curspeed+2*acc[j]*(d-curpos)))/acc[j];
				res=curt+et2;
				curpos=d;
			}
			else
			{
				long double maxpos=curpos+curspeed*t[0]+0.5*acc[j]*t[0]*t[0];
				if (maxpos<=p[0])
				{
					curpos=maxpos;
					curspeed=curspeed+acc[j]*t[0];
					curt=t[0];
				}
				else
				{
					curpos=p[0];
					curspeed=speed[1];
					curt=t[0];
				}

				for (int k=1;k<n;k++)
				{
					maxpos=curpos+curspeed*(t[k]-t[k-1])+0.5*acc[j]*(t[k]-t[k-1])*(t[k]-t[k-1]);
					if (maxpos<=p[k])
					{
						if (maxpos>=d)
						{
							long double extrat=(-curspeed+sqrt(curspeed*curspeed+2*acc[j]*(d-curpos)))/acc[j];
							res=curt+extrat;
							curpos=d;
							break;
						}
						else
						{
							curpos=maxpos;
							curspeed=curspeed+acc[j]*(t[k]-t[k-1]);
							curt=t[k];
						}
					}
					else
					{
						if (p[k]>=d)
						{
							long double et1=(d-p[k-1])/speed[k];
							long double et2=(-curspeed+sqrt(curspeed*curspeed+2*acc[j]*(d-curpos)))/acc[j];
							long double et=et1>et2?et1:et2;
							res=curt+et;
							curpos=d;
							break;
						}
						else
						{
							curpos=p[k];
							curspeed=speed[k];
							curt=t[k];
						}
					}
				}
			}
			if (curpos<d-1e-6)
			{

				long double extrat=(-curspeed+sqrt(curspeed*curspeed+2*acc[j]*(d-curpos)))/acc[j];
				res=curt+extrat;
			}
			printf("%.10f\n",res);
		}
		//cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}
