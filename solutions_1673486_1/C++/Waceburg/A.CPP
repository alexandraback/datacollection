#include<stdio.h>
#define INF 100000000
double mulp[100001],p[100001];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int A,B,t,c,i;
	double res;
	scanf("%d",&t);
	mulp[0]=1;
	for(c=1;c<=t;c++)
	{
		res=INF;
		printf("Case #%d: ",c);
		scanf("%d%d",&A,&B);
		for(i=1;i<=A;i++)
		{
			scanf("%lf",&p[i]);
			mulp[i]=mulp[i-1]*p[i];
		}
		if(2+B<res) res=2+B;
		if(mulp[A]*(B-A+1)+(1-mulp[A])*(2*B-A+2)<res) res=mulp[A]*(B-A+1)+(1-mulp[A])*(2*B-A+2);
		for(i=1;i<=A;i++)
		{
			if(mulp[A-i]*(2*i+B-A+1)+(1-mulp[A-i])*(2*i+2*B+2-A)<res) res=mulp[A-i]*(2*i+B-A+1)+(1-mulp[A-i])*(2*i+2*B+2-A);
		}
		printf("%.6f\n",res);
	}
	return 0;
}