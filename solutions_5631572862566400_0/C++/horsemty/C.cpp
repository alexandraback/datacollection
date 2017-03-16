#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int T,x,ans,num,dis[1100],sum,n,a[1100],anss,b[1100];
bool f[2000];
void dfs(int u)
{
	//cout<<u<<' ';
	dis[a[u]]=max(dis[a[u]],dis[u]+1);
	b[a[u]]--;
	f[u]=true;
	for(int i=1;i<=n;i++)
		if (b[i]==0 && !f[i])
			dfs(i);
}
int main()
{
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[i]=x;
			b[x]++;
		}
		ans=0;
		memset(dis,0,sizeof(dis));
		memset(f,false,sizeof(f));
		for(int i=1;i<=n;i++)
			if (b[i]==0 && !f[i])
				dfs(i);
		/*for(int i=1;i<=n;i++)
			cout<<dis[i]<<endl;
		cout<<endl;*/
		for(int i=1;i<=n;i++)
		{
			x=i;
			num=0;
			memset(f,false,sizeof(f));
			while(!f[x])
			{
				f[x]=true;
				x=a[x];
				num++;
				/*if (!f[x])
				{
					dis[x]=max(dis[x],num);
					//cout<<i<<' '<<x<<' '<<dis[x]<<endl;
				}*/
			}
			if (x==i)
				if (num>ans)
					ans=num;
		}
		sum=0;
		anss=0;
		//cout<<dis[3]<<' '<<dis[4]<<endl;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if (a[i]==j && a[j]==i)
				{
					sum++;
					//if (b[i]!=1 || b[j]!=1)
						anss=anss+2+dis[i]+dis[j];
				}
			}
			anss/=2;
		ans=max(anss,ans);
		printf("Case #%d: %d\n",t,ans);
	}
}