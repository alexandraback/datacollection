#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int cases;
double p[MAXN];
int main()
{
	int cases;
	scanf("%d",&cases);
	for (int tcase=1;tcase<=cases;tcase++)		
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for (int i=1;i<=a;i++)
			scanf("%lf",&p[i]);
		double ans=b+2;
		double now=1;
		for (int i=0;i<=a;i++)
		{
			ans=min(ans,a-i+b-i+1+(1-now)*(1+b));
			now*=p[i+1];
		}
		printf("Case #%d: %.10f\n",tcase,ans);
	}
	return 0;
}
