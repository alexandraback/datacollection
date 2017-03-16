#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

int a,b,T,id;
double p[100010];
double ans[100010],now,min;
int i,j;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (id=1;id<=T;id++)
	{
		memset(ans,0,sizeof(ans));
		ans[0]=1;
		scanf("%d%d",&a,&b);
		min=2+b;
		for (i=1;i<=a;i++)
		{
			scanf("%lf",&p[i]);
			ans[i] = ans[i-1] * p[i];
			if (min> ans[i-1] * p[i]*(b-i+a-i+1) + (1-ans[i-1]*p[i])*(b-i+a-i+b+2) )
				min=ans[i-1] * p[i]*(b-i+a-i+1) + (1-ans[i-1]*p[i])*(b-i+a-i+b+2);
		}
		printf("Case #%d: %0.6lf\n",id,min);
	}
	return 0;
}