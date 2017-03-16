#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int T,tt,N,A,i,k;
	double v,l,t[3],p[3],ac,time1,time2,v1,x;
	freopen("B-large.in","r",stdin);
	freopen("o.out","w",stdout);
	scanf("%d",&T);
	for(tt=1;tt<=T;++tt)
	{
		printf("Case #%d:\n",tt);
		scanf("%lf%d%d",&l,&N,&A);
		for(i=1;i<=N;++i)
			scanf("%lf%lf",&t[i],&p[i]);
		for(k=1;k<=A;++k)
		{
			scanf("%lf",&ac);
			time1=sqrt(2*l/ac);
			if(N==1 || p[1]>=l)
			{
				printf("%f\n",time1);
				continue;
			}

			v1=0;
			x=0;
			for(i=2;i<=N;++i)
			{
				if(p[i]>=l)
					break;
				v=(p[i]-p[i-1])/(t[i]-t[i-1]);
				x+=v1*(t[i]-t[i-1])+0.5*ac*(t[i]-t[i-1])*(t[i]-t[i-1]);
				if(x>p[i])
				{
					v1=v;
					x=p[i];
				}
			}
			time1=(-v1+sqrt(v1*v1-2*ac*(x-l)))/ac+t[i-1];
			time2=(l-p[i-1])/v+t[i-1];
			printf("%f\n",time1>time2?time1:time2);
		}
	}
	return 0;
}