#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int n,ans,p,a[1010];
void task()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=1000000000;
	for(int i=1;i<=1000;i++)
	{
		p=0;
		for(int j=1;j<=n;j++)
		{
			p+=(a[j]-1)/i;
		}
		ans=min(p+i,ans);
	}
	printf("%d\n",ans);
}
int main()
{
	int T;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(int ti=1;ti<=T;ti++)
	{
		printf("Case #%d: ",ti);
		task();
	}
}
