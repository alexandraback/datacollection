#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=100010;

int A,B;
double p[MAXN];
double pp[MAXN];

void init()
{
	scanf("%d%d",&A,&B);
	pp[0]=1;
	for(int i=1;i<=A;++i)
		scanf("%lf",&p[i]),pp[i]=p[i]*pp[i-1];
	double ans=B+2;
	for(int i=A;i>=0;--i)
	{
		ans=min(ans,pp[i]*(A-i+B-i+1)+(1-pp[i])*(A-i+B-i+1+B+1));
	}
	printf("%.6f\n",ans);
}
int main()
{
	int t,cases=1;
	for(scanf("%d",&t);t--;)
	{
		printf("Case #%d: ",cases++);
		init();
	}
	return 0;
}
