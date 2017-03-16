#include<iostream>
#include<stdio.h>
#include<math.h>
#define N 15
using namespace std;

double t[N];
double ai[N];
double x[N];

int main()
{
	int te,n,a;
	double d,ti,tmp,v,xt;
	int i,cas=1;
	freopen("re.txt","r",stdin);
    freopen("ans.txt","w",stdout);
	scanf("%d",&te);
	while(te--)
	{
	
		scanf("%lf%d%d",&d,&n,&a);
		for(i=0;i<n;i++)
		scanf("%lf%lf",&t[i],&x[i]);
		for(i=0;i<a;i++)
		scanf("%lf",&ai[i]);
		printf("Case #%d:\n",cas++);
		for(i=0;i<a;i++)
		{
			ti=sqrt(2*x[0]/ai[i]);
			if(ti-t[0]<=0.0000001)
			{
				ti=d/(x[1]-x[0])*(t[1]-t[0])+t[0];//cout<<ti<<"*********"<<endl;
			}
			else
			{
				ti=sqrt(2*d/ai[i]);
				tmp=d/(x[1]-x[0])*(t[1]-t[0])+t[0];
				v=(x[1]-x[0])/(t[1]-t[0]);//cout<<ti<<"^^^^^^^^^^^"<<endl;
				if(ti<tmp)
				{
					ti=(v+sqrt(v*v+2*a*x[0]))/ai[i];
					xt=x[0]+v*ti;//cout<<ti<<"%%%%%%%%"<<endl;
					ti+=(d-xt)/v;
				}
			}
			printf("%.7lf\n",ti);
		}
	}
	return 0;
}
					

