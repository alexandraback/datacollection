#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<cmath>
#include<cstdlib>

using namespace std;

const int maxn=200000;
double info[maxn];
double corr[maxn];
int a,b;
void init()
{
	scanf("%d%d",&a,&b);
	for (int i=1;i<=a;i++)
		scanf("%lf",&info[i]);
}
void work(int cas)
{
	int i;
	double ans=100000000;
	corr[0]=1;
	for (i=1;i<=a;i++)
		corr[i]=corr[i-1]*info[i];
	for (i=0;i<=a;i++)
		ans=min(ans,i+b-a+i+1+(1-corr[a-i])*(b+1));
	ans=min(ans,1.0+b+1);
	printf("Case #%d: %.9lf\n",cas,ans);
}
int main()
{
	freopen("alargein.txt","r",stdin);
	freopen("alargeout.txt","w",stdout);
	int cas,ii;
	scanf("%d",&cas);
	for (ii=1;ii<=cas;ii++)
	{
		init();
		work(ii);
	}
	return 0;
}