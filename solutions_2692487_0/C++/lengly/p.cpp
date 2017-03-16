#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define fi(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof(a))
#define mc(a,b) memcpy(a,b,sizeof(a))
using namespace std;

int n,m,a[20],ans;

void dfs(int dep,int nowans,int nowbig)
{
	if (dep>n)
	{
		ans=min(ans,nowans);
		return;
	}
	dfs(dep+1,nowans+1,nowbig);
	if(nowbig>1)
	{
		while (nowbig<=a[dep])
		{
			nowbig=nowbig*2-1;
			nowans++;
		}
		dfs(dep+1,nowans,nowbig+a[dep]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	fi(i,1,T)
	{
		scanf("%d%d",&m,&n);
		fi(j,1,n) scanf("%d",&a[j]);
		sort(a+1,a+n+1);
		ans=100000000;
		dfs(1,0,m);
		printf("Case #%d: %d\n",i,ans);
	}

	return 0;
}
