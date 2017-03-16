#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int const MAXN = 10;

int zip[MAXN],n;
bool visited[MAXN];
vector<vector<int>> g;
vector<int> ans;
vector<string> anss;

bool dfs(int here){
	visited[here]=1;
	ans.push_back(zip[here]);
	if(ans.size()==n){
		ostringstream oss;
		for(int i=0;i<ans.size();i++){
			oss<<ans[i];
		}
		anss.push_back(oss.str());
		return true;
	}
	int len=g[here].size(),there,i;
	for(i=0;i<len;i++){
		there=g[here][i];
		if(!visited[there])
			if(dfs(there))
				return true;
	}
	return false;
}

bool comp(int x,int y){
	return zip[x]<zip[y];
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,ti,m,i,j,s,e;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%d",zip+i);
		}
		g.clear();
		g.resize(n);
		for(i=0;i<m;i++){
			scanf("%d%d",&s,&e);
			s--;e--;
			g[s].push_back(e);
			g[e].push_back(s);
		}
		for(i=0;i<n;i++)
			sort(g[i].begin(),g[i].end(),comp);

		anss.clear();
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				visited[j]=0;
			ans.clear();
			dfs(i);

		}
		sort(anss.begin(),anss.end());
		
		
		printf("Case #%d: ",ti);
		cout<<anss[0];
		printf("\n");
	}
}