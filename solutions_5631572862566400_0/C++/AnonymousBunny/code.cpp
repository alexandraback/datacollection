#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define maxn 1010
#define mk mark
int f[maxn];
int cur;
vector <int> adj[maxn], st[maxn];
int vis[maxn];
int uu, cnt;
int mk[maxn], nt[maxn], cp[maxn], g[maxn];

bool dfs (int v, int p, int n){
//	cout<<v<<" ";
	cp[v]= cur;
	vis[v]= 1;
	if (f[v]==p) {
		g[v]= 1;
		return 1;
	}
	cnt++;
	if (cp[v]==cp[f[v]] and cnt<n) return 0;
	if (cp[v]==cp[f[v]]) return 1;
	if (cp[f[v]]!=0){
		if (g[f[v]]) {
			g[f[v]]= 0;
			return 1;
		}
		return 0;
	}
	return dfs (f[v], v, n);
}

bool check (vector <int> v, int n){
	for (int i=1; i<=n; i++){
		g[i]= 0;
		mark[i]= 0;
		cp[i]= 0;
		vis[i]= 0;
	}
	for (int i=0; i<v.size(); i++) mark[v[i]]= 1;
	for (int i=0; i<v.size(); i++){
		int q=0;
		if (!mark[f[v[i]]]) return 0;
		for (int j=0; j<st[v[i]].size(); j++){
			if (f[v[i]]==st[v[i]][j]) continue;
		//	cout<<"VIS "<<v[i]<<" "<<st[v[i]][j]<<endl;
			q+=mark[st[v[i]][j]];
			if (mark[st[v[i]][j]]) nt[v[i]]= st[v[i]][j];
		}
		if (q>1) return 0;
	}
	bool ok= 1;
	for (int i=0; i<v.size(); i++){
		if (!vis[v[i]]) {
			cur++;
			g[v[i]]=1;
			cnt= 0;
		//	cout<<"hi "<<v[i]<<endl;
			ok= dfs(v[i], -1, v.size());
		//	cout<<endl;
			if (!ok) return 0;
		}
	}
	return 1;

}

void reset(){
	cur=1;
	for (int i=0; i<maxn; i++){
		adj[i].clear();
		st[i].clear();
		nt[i]= 0;
		f[i]= 0;
		vis[i]= 0;
		mark[i]= 0;
		g[i]= 0;

	}
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for (uu=1; uu<=t; uu++){
		int n;
		cin>>n;
		reset();
		for (int i=1; i<=n; i++){
			cin>>f[i];
			adj[i].push_back(f[i]);
			st[f[i]].push_back(i);
		}
		vector <int> qq;

		int ans=0;
		for (int i=0; i<(1<<n); i++){
			qq.clear();
			for (int j=0; j<n; j++){
				if (i&(1<<j)) qq.push_back(j+1);
			}
			int p= qq.size();
			if (check(qq, n)) ans= max(ans, p);
		}
		cout<<"Case #"<<uu<<": "<<ans<<endl;
//		int a[6]= {1, 3, 4, 7, 9, 10};
//		for (int i=0; i<6; i++) qq.push_back(a[i]);
//		cout<<check(qq, n);





	}
	return 0;
}
