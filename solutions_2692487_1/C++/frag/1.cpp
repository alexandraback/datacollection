#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 110
using namespace std;
int cnt[maxn];
int a[maxn];
int n,m,ans;
void Doit()
{
	ans=12345678;
	int now=m;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(now>a[i])
		{
			now+=a[i];
			cnt[i]=cnt[i-1];
		}
		else 
		{
			if(now==1)
			{
				cnt[i]=123456789;
				now+=a[i];
			}
			else 
			{
				cnt[i]=cnt[i-1];
				while(now<=a[i])
				{
					cnt[i]++;
					now+=now-1;
				}
				now+=a[i];
			}
		}
	}
	for(int i=0;i<=n;i++)
		ans=min(ans,cnt[i]+n-i);
	printf("%d\n",ans);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&m,&n);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		printf("Case #%d: ",i);
		Doit();
	}
	return 0;
}
