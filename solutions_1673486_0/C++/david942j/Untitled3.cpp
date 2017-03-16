#include <cstdio>
const int N=100100;
int A,B;
double p[N],mul[N];
double wrg[N],sum[N];
double calc(int bk)
{
	double ans;
	ans=sum[A-bk]*(bk+B-(A-bk)+1+B+1) + (1.0-sum[A-bk])*(bk+B-(A-bk)+1);
	return ans;
}
int main()
{
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&A,&B);
		for(int i=1;i<=A;i++)
			scanf("%lf",&p[i]);
		mul[0]=1.0;
		for(int i=1;i<=A;i++)
			mul[i]=mul[i-1]*p[i];
		for(int i=1;i<=A;i++)
		{
			wrg[i]=mul[i-1]*(1.0-p[i]);
			sum[i]=sum[i-1]+wrg[i];
		}
		double kpans=0.0,ans=1e9,rtans;
		kpans=mul[A]*(B-A+1)+(1.0-mul[A])*(B-A+1+B+1);
		rtans=(1+B+1);
		ans=rtans>kpans?kpans:rtans;
		for(int i=1;i<=A;i++)
		{
			double bk=calc(i);
			if(bk<ans)ans=bk;
		}
		printf("Case #%d: %lf\n",w++,ans);
	}
}
