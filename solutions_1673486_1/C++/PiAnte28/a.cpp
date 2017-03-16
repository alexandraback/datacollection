#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps=1e-8;
const int maxn=100005;
double rec[maxn];
int a,b,tt,hehe;
double ans;

int dblcmp(double x)
{
	if (fabs(x)<eps) return 0;
	if (x>0) return 1;else return -1;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&tt);hehe=tt;
	while (tt--)
	{
		rec[0]=1.0;
		scanf("%d%d\n",&a,&b);
		for (int i=1;i<=a;i++)
		{
			scanf("%lf",&rec[i]);
			rec[i]*=rec[i-1];
		}
		ans=b+2.0;
		double temp;
		for (int i=a;i>=0;i--)
		{
			temp=rec[a-i]*(i*2+b-a+1)+(1.0-rec[a-i])*(i*2+b-a+1+b+1);
			if (dblcmp(ans-temp)>0) ans=temp;
		}
		printf("Case #%d: %lf\n",hehe-tt,ans);
	}
	return 0;
}
