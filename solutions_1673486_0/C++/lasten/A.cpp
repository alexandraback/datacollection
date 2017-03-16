#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define maxn 100010
double f[maxn];
double p[maxn];
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int cc=1;cc<=cas;cc++)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		for(int i=1;i<=A;i++)
			scanf("%lf",&f[i]);
		p[0]=1;
		for(int i=1;i<=B;i++)
			p[i]=p[i-1]*f[i];
		double ans=B+2;
		for(int i=0;i<=A;i++)
		{
			double tmp=A-i+p[i]*(B-i+1)+(1-p[i])*(B-i+1+B+1);
//			printf("%.4f\n",tmp);
			ans=min(ans,tmp);
		}
		printf("Case #%d: %.6f\n",cc,ans);
	}
	return 0;
}

