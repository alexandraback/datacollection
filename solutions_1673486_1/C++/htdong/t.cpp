#include <cstdio>

int t,q;
int a,b,i;
double p[100001],sum[100001],ans;

int main ()
{
	/*freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);*/
	scanf("%d",&t);
	for(q=1;q<=t;q++)
	{
		scanf("%d%d",&a,&b);
		sum[0]=1;
		for(i=1;i<=a;i++)
		{
			scanf("%lf",&p[i]);
			sum[i]=sum[i-1]*p[i];
		}
		ans=b+2;
		if(ans>(b-a+1)*sum[a]+(1-sum[a])*(b-a+1+b+1))ans=(b-a+1)*sum[a]+(1-sum[a])*(b-a+1+b+1);
		for(i=1;i<=a;i++)
			if(ans>sum[a-i]*(b-a+1+i*2)+(1-sum[a-i])*(b-a+1+i*2+b+1))ans=sum[a-i]*(b-a+1+i*2)+(1-sum[a-i])*(b-a+1+i*2+b+1);
		printf("Case #%d: %lf\n",q,ans);
	}
	
	return 0;
}

