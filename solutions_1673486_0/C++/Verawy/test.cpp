#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;

double p[101010];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T,a,b,i,j;
	double P,ans;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&a,&b);
		p[0]=1.0;
		for (i=1;i<=a;i++) scanf("%lf",&p[i]);
		ans=b+2;
		for (i=0;i<=a;i++)
		{
			P=1.0;
			for (j=1;j<=a-i;j++) P*=p[j];
			double t=P*(2*i+b-a+1)+(1-P)*(2*i+2*b-a+2);
			if (ans>t) ans=t;
		}
		printf("Case #%d: %.10f\n",tt,ans);
	}
	return 0;
}
