#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int tests,test,a,b;
double ans;
double p[100010],q[100010];

int main()
{
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	scanf("%d",&tests);
	for (test=1;test<=tests;test++)
	{
		scanf("%d%d",&a,&b);
		for (int i=1;i<=a;i++) scanf("%lf",p+i);
		q[0] = 1;
		for (int i=1;i<=a;i++) q[i] = q[i-1] * p[i];
		ans = b+2;
		for (int i=1;i<=a;i++)
		{
			ans = min(ans, (a-i+b-i+1)*q[i]+(a-i+b-i+1+b+1)*(1-q[i]));
		}
		printf("Case #%d: %f\n",test,ans);
	}
	return 0;
}
