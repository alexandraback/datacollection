#include<cstdio>
#include<algorithm>
using namespace std;
int a,b;
double ans1,ans2,ans3,f[100000],x[100000];
int main()
{
	//freopen("password.in","r",stdin);
	//freopen("password.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int tt=1;tt<=t;++tt)
		{
			scanf("%d%d",&a,&b);
			f[0]=1.0;
			for (int i=1;i<=a;++i)
				{
					scanf("%lf",&x[i]);
					f[i]=f[i-1]*x[i];
				}
			ans1=b+2;
			ans2=b-a+1+b+1;
			for (int i=1;i<=a;++i)
				ans2=min(b-i+1+(1-f[i])*(b+1)+a-i,ans2);
			printf("Case #%d: %.6lf\n",tt,min(ans1,ans2));
		}
}

