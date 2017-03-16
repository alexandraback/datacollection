#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;
#define N 2100
struct Graph{
	int n, m;
	int vis[N], m1[N], m2[N];
	vector<int> adj[N];
	Graph(){
	}
	void add_edge(int x, int y){
//		printf("add %d %d\n", x, y);
		adj[x].push_back(y);
	}
	int dfs(int x){
		if (vis[x]) return 0;
		vis[x] = 1;
		for (auto y : adj[x]){
			if (m2[y] == -1){
				m1[x] = y;
				m2[y] = x;
				return 1;
			}
			if (dfs(m2[y])){
				m1[x] = y;
				m2[y] = x;
				return 1;
			}
		}
		return 0;
	} 
	int matching(){
		int ret = 0;
		memset(m1, -1, sizeof(m1));
		memset(m2, -1, sizeof(m2));
		for (int k = 0; k < n; k++){
			int tmp = 0;
			memset(vis, 0, sizeof(vis));
			for (int i = 0; i < n; i++){
				if (m1[i] == -1){
					//for (int j = 0; j < n; j++) vis[j] = 0;
					tmp += dfs(i);
				}
			}
			if (!tmp) break;
			ret += tmp;
		}
		return ret;
	}
}g;
void init_g(){
	FOR(i,0,1010) g.adj[i].clear();
}
/* 
int find(){
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	g.n = n;
	g.m = m;
	for (int i = 0;i < p; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		g.add_edge(x - 1, y - 1);
	}
	printf("%d\n", g.matching());
	return 0;
}
*/
unordered_map<string, int> mp[2];
int d[2][N];
int vis[2][N];
int n, m;
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		int left = 0, right = 0;
		scanf("%d", &n);
		init_g();
		mp[0].clear();
		mp[1].clear();
		memset(vis, 0, sizeof(vis));
		unordered_set<int> v1[N], v2[N];
		int edg = n;
		FOR(i,0,n){
			char s1[100], s2[100];
			scanf("%s%s", s1, s2);
			if (!mp[0].count(s1)) mp[0][s1] = left++;
			if (!mp[1].count(s2)) mp[1][s2] = right++;
			v1[mp[0][s1]].insert(mp[1][s2]);
			v2[mp[1][s2]].insert(mp[0][s1]);
		}
		FOR(i,0,left) d[0][i] = v1[i].size();
		FOR(i,0,right) d[1][i] = v2[i].size();
		FOR(i,0,left) if (d[0][i] == 1){
			if (!v1[i].size()) continue;
			int y = *v1[i].begin();
			vis[0][i] = vis[1][y] = 1;
			v2[y].erase(i);
			v1[i].clear();
			edg--;
		}
		FOR(i,0,right) if (d[1][i] == 1){
			if (!v2[i].size()) continue;
			int y = *v2[i].begin();
			vis[1][i] = vis[0][y] = 1;
			v1[y].erase(i);
			v2[i].clear();
			edg--;
		}
		g.n = left;
		g.m = right;
		FOR(i,0,left) if (!vis[0][i]){
			for (auto y : v1[i]){
				if (!vis[1][y]) g.add_edge(i, y);
			}
		}
		int mat = g.matching();
		//printf("match %d\n", mat);
		edg -= mat;
		FOR(i,0,left) if (g.m1[i] != -1) vis[0][i] = 1;
		FOR(i,0,right) if (g.m2[i] != -1) vis[1][i] = 1;
		FOR(i,0,left) for (auto y : v1[i]){
			if (!vis[0][i] || !vis[1][y]){
				vis[0][i] = vis[1][y] = 1;
				edg--;
			}
		}
		//g.matching();
		printf("Case #%d: %d\n", cc, edg);
	}
	return 0;
}

