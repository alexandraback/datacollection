#include<cstdio>
#include<iostream>
#include<cstring> 
#define cout(n) printf("%d\n",n)
using namespace std;
#define mod 1000000007 
int adj[27][27],coun[27],vis[27];
long long int fact[108];
 
long long int dfs(int node)
{
	vis[node]=1;
	long long int ret=fact[coun[node]];
	for(int j=0;j<27;j++)
	{
		if(adj[node][j]&&!vis[node])
			ret=(ret*1LL*dfs(j))%mod;
	}
	return ret;
} 
void pre()
{
		fact[0]=1LL;

	for(int i=1;i<=100;i++)
	{
		fact[i]=(fact[i-1]*1LL*i)%mod;
	}
}
int main()
{
	pre();
	int m,t,i,j,k,l,n;
	int tt;
	scanf("%d",&t);
	tt=1;
	
	while(t--)
	{
		memset(adj,0,sizeof(adj));
		memset(coun,0,sizeof(coun));
		scanf("%d",&n);
		int fg=1;
		string s[n+9];
		int indeg[27];
		memset(indeg,0,sizeof(indeg));
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			int st=s[i][0]-'a';
			int gg=0;
			for(j=1;j<s[i].length();j++)
			{
				int val=s[i][j]-'a';
				if(val==st)
					continue;
				gg=1;
				adj[st][val]++;
				indeg[val]++;
				if(adj[st][val]>1)
					fg=0;
				st=val;
			}
			if(!gg)
				coun[st]++;
		}
		for(i=0;i<26;i++)
		{
			int c=0;
			for(j=0;j<26;j++)
			{
				if(i==j)
					continue;
				if(adj[i][j])
					c++;
			}
			if(c>1)
				fg=0;
		}
		cout<<"Case #"<<tt++<<": ";
		if(!fg)
			cout<<"0\n";
		else
		{
			long long int ans=1LL;
			int c=0;
			for(i=0;i<26;i++)
			{
				if(vis[i]||indeg[i])
					continue;
				int zz=0;
				if(coun[i])
					zz=1;
				for(j=0;j<26;j++)
				{
					if(adj[i][j])
					zz=1;
				}
			if(!zz)
				continue;
			long long int z=dfs(i);
			ans=(ans*1LL*z)%mod;
			c++;
		}
		ans=(ans*1LL*fact[c])%mod;
		cout<<ans<<"\n";
	}
}
return 0;
}