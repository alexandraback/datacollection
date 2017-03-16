#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> g[1010];
int dis1[1010][1010],dis2[1010][1010],lon[1010];
int f[1010];
bool fou[1010];
void dfs1(int root,int now,int di)
{
	fou[now]=true;
	dis1[root][now]=di;
	++di;
	int i=g[now].size();
	while(i--)
	{
		if(!fou[g[now][i]])
		{
			dfs1(root,g[now][i],di);
		}
	}
	return;
}

void dfs2(int root,int now,int di)
{
	fou[now]=true;
	if(now==f[root])
	{
		return;
	}
	dis2[root][now]=di;
	++di;
	int i=g[now].size();
	while(i--)
	{
		if(!fou[g[now][i]])
		{
			dfs2(root,g[now][i],di);
		}
	}
	return;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int i,j,T,cas=0,n,ans1,ans2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			g[i].clear();
		}
		for(i=1;i<=n;++i)
		{
			scanf("%d",&f[i]);
			g[f[i]].push_back(i);//´æ·´Ïò±ß
		}
		
		for(i=1;i<=n;++i)
		{
			memset(dis1[i],0,sizeof(int)*(n+1));
			memset(fou,false,sizeof(bool)*(n+1));
			dfs1(i,i,0);
			memset(dis2[i],0,sizeof(int)*(n+1));
			memset(fou,false,sizeof(bool)*(n+1));
			dfs2(i,i,0);
			lon[i]=*max_element(dis2[i]+1,dis2[i]+n+1);
		}
		
		ans1=ans2=0;
		for(i=1;i<n;++i)
		{
			for(j=i+1;j<=n;++j)
			{
				if(f[i]==j&&f[j]==i)
				{
					ans2+=2+lon[i]+lon[j];
				}
				if(dis1[i][j]>0&&dis1[j][i]>0)
				{
					ans1=max(ans1,dis1[i][j]+dis1[j][i]);
				}
			}
		}
		
		printf("Case #%d: %d\n",++cas,max(ans1,ans2));
	}
	return 0;
}
/*
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
*/

