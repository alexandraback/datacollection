#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int T,tt,N,A,i;
	double v,l,t[3],p[3],ac,time1,time2;
	//freopen("B-small-attempt1.in","r",stdin);
	//freopen("o.out","w",stdout);
	scanf("%d",&T);
	for(tt=1;tt<=T;++tt)
	{
		printf("Case #%d:\n",tt);
		scanf("%lf%d%d",&l,&N,&A);
		for(i=1;i<=N;++i)
			scanf("%lf%lf",&t[i],&p[i]);
		for(i=1;i<=A;++i)
		{
			scanf("%lf",&ac);
			time1=sqrt(2*l/ac);
			if(N==1 || p[1]>=l)
			{
				printf("%f\n",time1);
				continue;
			}
			v=(p[2]-p[1])/(t[2]-t[1]);
			time2=(l-p[1])/v+t[1];
			printf("%f\n",time1>time2?time1:time2);
		}
	}
	return 0;
}