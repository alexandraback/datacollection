#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
vector<int> v[1005];
vector<int> v2[1005];
int visited[1005];
int dfs2(int node)
{
	int n=v2[node].size(),ans=0,i;
	for(i=0;i<n;i++)
	{
		if(visited[v2[node][i]]==0)
		{
			visited[v2[node][i]]=1;
			ans=max(ans,dfs2(v2[node][i]));
			visited[v2[node][i]]=0;
		}
	}
	return ans+1;
}
int dfs(int node, int parent)
{
	visited[node]=1;
	//int ans=0;
	if(v[node][0]!=parent&&visited[v[node][0]]==0)
	{
		int x=dfs(v[node][0],parent);
		if(x==-1)
			return x;
		else
		return 1+x;
	}
	else if(v[node][0]==parent)
		{
			if(v[v[node][0]][0]==node)
				{
					int x=dfs2(node);
					return x;
				}
			return 1;
		}
	else if(v[node][0]!=parent&&visited[v[node][0]]==1)
		{
			if(v[v[node][0]][0]==node)
				{
					int x=dfs2(node);
					return x;
				}
			return -1;
		}
}

int main()
{
	int i,j,k,x,n,ans=1;
	freopen("C-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	sd(t);
	for(x=1;x<=t;x++)
	{
		ans=0;
		sd(n);
		for(i=1;i<=n;i++)
		{
			v[i].clear();
			v2[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			sd(j);
			v[i].push_back(j);
			v2[j].push_back(i);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				visited[j]=0;
			int z=dfs(i,i);
			//printf("%d\n",z );
			if(z==-1)
				ans=max(ans,1);
			
			else
				ans=max(ans,z);
		}
		int temp=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(v[i][0]==j&&v[j][0]==i)
					temp++;
			}
		}
		//temp/=2;
		if(temp>1)
			ans=max(ans,4);
		printf("Case #%d: %d\n",x,ans);
	}
	return 0;
}