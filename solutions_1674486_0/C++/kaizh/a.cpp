#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool vis[1010];
int indeg[1010]={0},outdeg[1010]={0};
bool adj[1010][1010];
int N;
bool flag;

void gao(int cur)
{
	if(flag)return;
	for(int i=1;i<=N;i++)
		if(adj[cur][i])
		{
			if(vis[i])
			{
				flag=true;
				return;
			}
			vis[i]=true;
			gao(i);
		}
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.res","w+",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		memset(vis,false,sizeof(vis));
		memset(indeg,0,sizeof(indeg));
		memset(adj,false,sizeof(adj));
		flag=false;
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			cin>>outdeg[i];
			int t;
			for(int j=0;j<outdeg[i];j++)
			{
				cin>>t;
				adj[i][t]=true;
				indeg[t]++;
			}
		}
		int st=1;
		for(int i=1;i<=N&&flag==false;i++)
			if(indeg[i]==0)
			{
				memset(vis,false,sizeof(vis));
				gao(i);
			}
		cout<<"Case #"<<tt<<": ";
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
