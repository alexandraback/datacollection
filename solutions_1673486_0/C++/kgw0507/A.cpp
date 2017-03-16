#include <stdio.h>

const int B=100100;
int TC,tc,a,b;
double p[B+1],r,s,Ans;

int main()
{
	int i,k;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	for(scanf("%d",&TC),tc=1;tc<=TC;++tc)
	{
		scanf("%d%d",&a,&b);
		p[0]=1;
		for(i=1;i<=a;++i)
			scanf("%lf",&p[i]);
		Ans=1+b+1;
		r=1;
		for(k=a;k>=0;--k)
		{
			i=a-k; r*=p[i];
			s=2*k+(b-a+1)+(b+1)*(1-r);
			if(s<Ans) Ans=s;
		}
		printf("Case #%d: %.6f\n",tc,Ans);
	}
	return 0;
}