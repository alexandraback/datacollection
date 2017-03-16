/*
  Kosaraju's O(n + m) time, two pass algo
  Tested on : spoj BOTTOM
*/
#include <bits/stdc++.h>

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

using namespace std;

const int MAXN = 100000;

vector<int> List[MAXN];
vector<int> rev_List[MAXN];

void dfs(int u, int& cur_t, vector<bool>& vis, vector<int>& tm){
	vis[u] = 1;
	for(int c : rev_List[u]) if(!vis[c]) {
		dfs(c, cur_t, vis, tm);
	}
	tm[cur_t++] = u;
}

void dfs2(int u, int comp_num, vector<int>& v){
	v[u] = comp_num;
	for(int c : List[u]) if(v[c] == -1){
		dfs2(c, comp_num, v);
	}
	return ;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; ++tc) {
		printf("Case #%d: ", tc);
		int n, m;
		scanf("%d", &n);
		vector<int > frnd(n);
		m = n;
		for(int i = 0; i < m; ++i){
			int u, v; // 0-based nodes. directed edge from u to v
			scanf("%d", &v); v -= 1;
			u = i;
			List[u].push_back(v);
			frnd[i] = v;
			rev_List[v].push_back(u);
		}
		vector<bool> vis(n, 0); 
		vector<int> tm(n, -1); // tm[t] = node which was last-visited at time = t
		vector<int> which_comp(n, -1); 
		// which_comp[i] = connected component number where node i belongs to
		// connected component number is  defined as the node with minimum index
		// in that particular connected component
		int cur_t = 0;
		for(int i = 0; i < n; ++i) if(!vis[i]) {
			dfs(i, cur_t, vis, tm);
		}
		for (int i = n-1; i >= 0; --i) if(which_comp[tm[i]] == -1){
			dfs2(tm[i], tm[i], which_comp);
		}
		vector<int> cnnt(n, 0);
		for(int i = 0; i < n; ++i){
			cnnt[which_comp[i]] += 1;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i){
			ans = max(ans, cnnt[i]);
		}
		vector<pii> v;
		rep(i, n) rep(j, i) {
			if(frnd[i] == j && frnd[j] == i) v.push_back(make_pair(i, j));
		}
		queue<int> Q;
		vector<int> dist(n, 100000000);
		vector<int> root(n, -1);
		for(pii p : v){
			Q.push(p.X);
			Q.push(p.Y);
			dist[p.X] = 0;
			dist[p.Y] = 0;
			root[p.X] = p.X;
			root[p.Y] = p.Y;
			// cerr << p.X << " " << p.Y << "\n";
		}
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for(int c : rev_List[u]) if(dist[c] > dist[u] + 1) {
				dist[c] = dist[u] + 1;
				Q.push(c);
				root[c] = root[u];
			}
		}
		int ans1 = 0;
		for(pii p : v) {
			vector<int> d1, d2;
			for(int i = 0; i < n; ++i) if(rev_List[i].size() == 0) {
				if(root[i] == p.X) {
					d1.push_back(dist[i]);
				}
				else if(root[i] == p.Y) d2.push_back(dist[i]);
			}
			sort(d1.begin(), d1.end(), greater<int>());
			sort(d2.begin(), d2.end(), greater<int>());

			ans1 += 2;
			if(d1.size() > 0) ans1 += d1[0];
			if(d2.size() > 0) ans1 += d2[0];
		}
		for(int i = 0; i < n; ++i) List[i].clear(), rev_List[i].clear();
		printf("%d\n", max(ans1, ans));
	}
	return 0;
}
