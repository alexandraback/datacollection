#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
int dfs(vector<vector<int > > & adj,int cur,int par,vector<int> &visit)
{
	if(visit[cur]==0)
	{
		visit[cur]=1;
		int mi=0;
		for(auto i:adj[cur])
		{
			if(i!=par)
			mi = max(mi,dfs(adj,i,cur,visit));
		}
		return 1+mi;
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	for(int ic=1;ic<=t;++ic)
	{
		cout<<"Case #"<<ic<<": ";
		cin>>n;
		vector<int> arr(n+1);
		for(int i=1;i<=n;++i) cin>>arr[i];
		vector<int> visit(n+1);
		vector<vector<int> > rev(n+1);
		for(int i=1;i<=n;++i)
		{
			rev[arr[i]].push_back(i);
		}

		int ans=0;
		for(int i=1;i<=n;++i)
		{
			memset(&visit[0],(n+1)*sizeof(int),0);
			if(visit[i]==0)
			{
				int cnt=0;
				int j = i,prev=-1;
				while(visit[j]==0)
				{
					++cnt;
					visit[j] = 1;
					prev=j;
					j = arr[j];
				}
				auto nw(visit);
				nw[prev]=0;
				ans = max(ans,cnt+dfs(rev,prev,-1,nw)-1);
			}
		}
		cout<<ans<<endl;
	}
}
