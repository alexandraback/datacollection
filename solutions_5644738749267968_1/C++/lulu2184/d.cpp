#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T,TT,n;
double a[1010],b[1010];
bool used[1010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		sort(&a[1],&a[n+1]);
		for (int i=1;i<=n;i++)
			scanf("%lf",&b[i]);
		sort(&b[1],&b[n+1]);
		int cnt=0,ans1=0,ans2=0;
		memset(used,0,sizeof(used));
		for (int i=1;i<=n;i++)
		{
			bool flag=false;
			for (int j=1;j<=n;j++)
				if (!used[j] && b[j]>a[i]) 
				{
					flag=true,used[j]=true,cnt++; 
					break;
				}
			if (!flag) 
				for (int j=1;j<=n;j++)
				{
					if (!used[j]) 
					{
						used[j]=true;
						break;
					}
				}
		}
		ans2=n-cnt;
		memset(used,0,sizeof(used));
		cnt=0;
		for (int i=n;i>=1;i--)
		{
			bool flag=false;
			for (int j=1;j<=n;j++)
				if (!used[j] && b[j]>a[i]) 
				{
					flag=true,used[j]=true,cnt++; 
					break;
				}
			if (!flag) 
				for (int j=1;j<=n;j++)
				{
					if (!used[j]) 
					{
						used[j]=true;
						break;
					}
				}
		}
		ans2=max(ans2,n-cnt);
		for (int i=0;i<=n;i++)
		{
			bool flag=true;
			for (int j=1;j<=n-i;j++)
			{
				if (a[j+i]<b[j]) 
				{
					flag=false;
					break;
				}
			}
			if (flag) { ans1=n-i;break; }
		}
		printf("Case #%d: %d %d\n",++TT,ans1,ans2);
	}

	return 0;
}