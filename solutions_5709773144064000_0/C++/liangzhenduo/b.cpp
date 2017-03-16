#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double c,f,x;
int main()
{
	freopen("bb.in","r",stdin);
	int T;
	scanf("%d",&T);
	for(int tcase=1;tcase<=T;tcase++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		double now=2;
		double t=0;
		double ans=1e100;
		for(int i=0;i<=ceil(x);i++)
		{
			ans=min(ans,t+x/now);
			t+=c/now;
			now+=f;
		}
		printf("Case #%d: %.7lf\n",tcase,ans);
	}
}
