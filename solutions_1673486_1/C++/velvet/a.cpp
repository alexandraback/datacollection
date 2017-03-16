#include <cstdio>
#include <iostream>
#define maxn 100009
using namespace std;
double c[maxn];
double d[maxn];

int main()
{
	int T,a,b;
	cin>>T;
	double ans,p;
	d[0]=1;
	for (int t=1;t<=T;t++)
	{
		cin>>a>>b;
		ans=b+2;
		for (int i=1;i<=a;i++) scanf("%lf",c+i),d[i]=d[i-1]*c[i];
		for (int i=1;i<=a;i++)
		{
			p=b-a+1+2*i+(1-d[a-i])*(b+1);
			if (p<ans) ans=p;
		}
		p=d[a]*(b-a+1)+(1-d[a])*(b-a+b+2);
		if (p<ans) ans=p;
		printf("Case #%d: %.8f\n",t,ans);
	}
	return 0;
}
