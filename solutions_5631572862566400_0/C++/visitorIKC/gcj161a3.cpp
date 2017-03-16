#include <bits/stdc++.h>

using namespace std;
int bff[1119];
vector<vector<int> >g;
int dfs(int now,int pa){
	int ans=1;
	for(int i=0;i<g[now].size();i++){
		int target=g[now][i];
		if(target==pa)continue;
		ans=max(ans,dfs(target,now)+1);
	}
	return ans;
}
int solvejellyfish(int n){
	vector<pair<int,int> >tcyc;
	for(int i=0;i<n;i++){
		if(bff[bff[i]]==i&&i<bff[i])tcyc.push_back({i,bff[i]});
	}
	int ans=0;
	for(int i=0;i<tcyc.size();i++){
		ans+=dfs(tcyc[i].first,tcyc[i].second)+dfs(tcyc[i].second,tcyc[i].first);
	}
	return ans;
}
bool used[1119];
int kth[1119];
int findcyc(int n){
	memset(used,0,sizeof(used));
	int t=bff[n],ans;
	for(ans=1;t!=n;t=bff[t],ans++){
		if(used[t])return -1;
		used[t]=1;
	}
	return ans;
}
int solvecyc(int n){
	int ans=0;
	for(int i=0;i<n;i++){
		int res=findcyc(i);
		if(res!=-1){
			ans=max(ans,res);
		}
	}
	return ans;
}
int main(){
	int tc,i=0;
	cin>>tc;
	while(tc-->0){
		i++;
		g.clear();
		int n;
		cin>>n;
		g.resize(n);
		for(int i=0;i<n;i++){
			cin>>bff[i];
			bff[i]--;
			g[i].push_back(bff[i]);
			g[bff[i]].push_back(i);
		}
		cout<<"Case #"<<i<<": "<<max(solvecyc(n),solvejellyfish(n))<<endl;
	}
	return 0;
}
