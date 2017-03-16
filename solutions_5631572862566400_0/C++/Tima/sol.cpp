#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = 2000, mod = int(1e9)  + 7;
int T;
bool used[N];
int f[N],n,d[N],sz;
int ok[N];
vector <int> order,gr[N],g[N];
queue <int> q;

void dfs1(int v){
	used[v] = 1;
	int to = f[v];
	if(!used[to]) dfs1(to);
	order.push_back(v);
}

void dfs2(int v){
	used[v] = 1;
	sz++;
	for(int i=0;i<gr[v].size();i++){
		if(!used[gr[v][i]]) dfs2(gr[v][i]);
	}
}

int bfs(int v, int id){
	while(!q.empty()) q.pop();
	q.push(v);
	d[v] = 0;
	ok[v] = id;
	int res = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int to = g[u][i];
			if(ok[to] != id){
				ok[to] = id;
				d[to] = d[u] + 1;
				res = max(res,d[to]);
				q.push(to); 
			}
		}
	}	
	return res;
}

int main () {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&f[i]);
			f[i]--;
			gr[f[i]].pb(i);
		}
		for(int i=0;i<n;i++){
			if(f[f[i]] != i) g[f[i]].pb(i);
		}
		int ans = 0;
		memset(used,0,sizeof(used));
		order.clear();
		for(int i=0;i<n;i++){
			if(!used[i]) dfs1(i);
		}
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++){
			int v = order[n-1-i];
			if(!used[v]){
				sz = 0;
				dfs2(v);
				ans = max(ans,sz);
			}
		}
		int res = 0;
		memset(used,0,sizeof(used));
		memset(ok,0,sizeof(ok));
		int m = 0;
		for(int i=0;i<n;i++){
			if(f[f[i]] == i && i < f[i]){
				int cur = bfs(i,++m) + bfs(f[i],++m);
				res += cur + 2;
			}
		}
		printf("%d\n",max(ans,res));
		for(int i=0;i<n;i++) {gr[i].clear(); g[i].clear();}
	}


return 0;
}