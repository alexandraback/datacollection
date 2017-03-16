#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double t[2100],x[2100],D;

double jie(double a,double b,double c)
{
	return (-b+sqrt(b*b-4*a*c))/2/a;
}

double cal(double g)
{
	double a,b,c,time,v;
	a=0.5*g;
	v=(x[1]-x[0])/(t[1]-t[0]);
	b=-v;
	c=-x[0];
	time=jie(a,b,c);
    
	if(time>(D-x[0])/v) return sqrt(2*D/g);
	else return (D-x[0])/v;
}

int main()
{
	int ca,n,m,test=0,i;
	double g;

	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%lf%d%d",&D,&n,&m);
		for(i=0;i<n;i++) scanf("%lf%lf",&t[i],&x[i]);
     
		printf("Case #%d:\n",++test);

		for(i=0;i<m;i++)
		{
			scanf("%lf",&g);
			if(n==1) printf("%lf\n",sqrt(2*D/g));
            else printf("%lf\n",cal(g));
		}
	}
	return 0;
}