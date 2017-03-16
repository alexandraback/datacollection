#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=100001;
const int INF=0x7FFFFFFF;
const double eps=1e-8;
const double pi=acos(-1.0);

int n,ca;
int indu[10000],vis[10000];
vector<int> g[MAXN];

void init(){
	cin>>n;
	int m,x;
	memset(g,0,sizeof(g));
	memset(indu,0,sizeof(indu));
	for (int i=1; i<=n; i++){
		cin>>m;
		for (int j=0; j<m; j++){
			cin>>x;
			g[x].push_back(i);
			++indu[i];
		}
	}
}

void dfs(int node){
	++vis[node];
	for (int i=0; i<g[node].size(); i++)
		dfs(g[node][i]);
}

void solve(){
	memset(vis,255,sizeof(vis));
	for (int i=1; i<=n; i++)
		if (indu[i]==0)
			dfs(i);
	for (int i=1; i<=n; i++)
		if (vis[i]>1){
			cout<<"Yes"<<endl;
			return;
		}
	cout<<"No"<<endl;
}

int main(){
	freopen("A.out","w",stdout);
	cin>>ca;
	for (int i=1; i<=ca; i++){
		cout<<"Case #"<<i<<": ";
		init();
		solve();
	}
	return 0;
}

