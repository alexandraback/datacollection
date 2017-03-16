#include <bits/stdc++.h>
using namespace std;
int n;
int bff[1010];
vector<int> g[1010];
int d[1010],ids[1010];
int ans;
void dfs(int i,int id,int dep)
{
	d[i]=dep;
	ids[i]=id;
	if(d[bff[i]]==-1)
		dfs(bff[i],id,dep+1);
	else if(ids[bff[i]]==id)
		ans=max(ans,dep-d[bff[i]]+1);
}
//pair<int,int> max2(pair<int,int> a,pair<int,int> b)
//{
//	vector<int> tmp={a.first,a.second,b.first,b.second};
//	sort(tmp.begin(), tmp.end(),greater<int>());
//	return {tmp[0],tmp[1]};
//}
//pair<int,int> dfs2(int i,int dep)
//{
//	pair<int,int> res={dep,0};
//	for(int j:g[i])
//		if(bff[i]!=j)
//			res=max2(res,dfs2(j,dep+1));
//	return res;
//}
int dfs2(int i,int dep)
{
	//cout<<i<<endl;
	int res=dep;
	for(int j:g[i])
		if(bff[i]!=j)
			res=max(res,dfs2(j,dep+1));
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T,no=0;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>bff[i];
			g[bff[i]].push_back(i);
		}
		ans=0;
		for(int i=1;i<=n;i++)
			if(bff[bff[i]]==i)
				ans+=dfs2(i,1);
		memset(d,-1,sizeof d);
		for(int i=1;i<=n;i++)
			if(d[i]==-1)
				dfs(i,i,0);
		cout<<"Case #"<<++no<<": "<<ans<<'\n';
	}
}