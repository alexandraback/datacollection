#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<limits>
using namespace std;

typedef long long LL;


int main(int argc, char *argv[])
{
#ifdef CHAOS
	freopen("data.in","r",stdin);
#endif
	int T;
	cin>>T;
	int t;
	for(t=1;t<=T;++t)
	{
		cout<<"Case #"<<t<<": ";
		int N;
		cin>>N;
		vector<int> adj[1024];
		bool vis[1024];
		memset(vis,0,sizeof(vis));
		int i;
		for(i=1;i<=N;++i)
		{
			int M;
			cin>>M;
			int j,x;
			for(j=0;j<M;++j)
			{
				cin>>x;
				adj[i].push_back(x);
				vis[x]=true;
			}
		}
		bool flag=false;
		for(i=1;i<=N;++i)
		{
			if(vis[i]) continue;
			int cnt[1024];
			memset(cnt,0,sizeof(cnt));
			queue<int>Q;
			Q.push(i);
			cnt[i]=1;
			int j;
			while(!Q.empty())
			{
				int x=Q.front();
				Q.pop();
				for(j=0;j<adj[x].size();++j)
				{
					int y=adj[x][j];
					Q.push(y);
					cnt[y]+=cnt[x];
				}
			}
			for(j=1;j<=N;++j)
			{
				if(cnt[j]>1) flag=true;
				//cout<<j<<":"<<cnt[j]<<endl;
			}

		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

	}
	return 0;
}
