/*
ID: ashish1610
PROG:
LANG: C++
Max flow code taken from : https://sites.google.com/site/indy256/algo_cpp/dinic_flow
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define MOD				1000000007
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
const int maxnodes = 3005;
int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];
struct Edge {
	int to, rev;
	int f, cap;
};
vector < Edge > g[maxnodes];
void addEdge(int s, int t, int cap) {
	Edge a = {t, g[t].size(), 0, cap};
	Edge b = {s, g[s].size(), 0, 0};
	g[s].push_back(a);
	g[t].push_back(b);
}
bool dinic_bfs() {
	fill(dist, dist + nodes, -1);
	dist[src] = 0;
	int qt = 0;
	q[qt++] = src;
	for (int qh = 0; qh < qt; qh++) {
		int u = q[qh];
		for (int j = 0; j < (int) g[u].size(); j++) {
			Edge &e = g[u][j];
			int v = e.to;
			if (dist[v] < 0 && e.f < e.cap) {
				dist[v] = dist[u] + 1;
				q[qt++] = v;
			}
		}
	}
	return dist[dest] >= 0;
}
int dinic_dfs(int u, int f) {
	if (u == dest)
		return f;
	for (int &i = work[u]; i < (int) g[u].size(); i++) {
		Edge &e = g[u][i];
		if (e.cap <= e.f) continue;
		int v = e.to;
		if (dist[v] == dist[u] + 1) {
			int df = dinic_dfs(v, min(f, e.cap - e.f));
			if (df > 0) {
				e.f += df;
				g[v][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}
int maxFlow(int _src, int _dest) {
	src = _src;
	dest = _dest;
	int result = 0;
	while (dinic_bfs()) {
		fill(work, work + nodes, 0);
		while (int delta = dinic_dfs(src, INT_MAX))
			result += delta;
	}
	return result;
}
int main() {
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		for(int i = 0; i < 3005; ++i) {
			g[i].clear();
			dist[i] = 0;
			work[i] = 0;
		}
		int n;
		cin >> n;
		vector < string > v1, v2;
		set < string > s1, s2;
		set < string > :: iterator it;
		map < string, int > mp1, mp2;
		string str, str1;
		for(int i = 0; i < n; ++i) {
			cin >> str >> str1;
			v1.push_back(str);
			s1.insert(str);
			v2.push_back(str1);
			s2.insert(str1);
		}
		int cnt = 1;
		src = 0;
		dest = 3000;
		for(it = s1.begin(); it != s1.end(); ++it) {
			addEdge(src, cnt, 1);
			mp1[(*it)] = cnt;
			cnt += 1;
		}
		int res = cnt - 1;
		cnt = 1;
		for(it = s2.begin(); it != s2.end(); ++it) {
			addEdge(1500 + cnt, dest, 1);
			mp2[(*it)] = cnt;
			cnt += 1;
		}
		res += (cnt - 1);
		for(int i = 0; i < n; ++i) {
			addEdge(mp1[v1[i]], mp2[v2[i]] + 1500, 1);
		}
		res -= maxFlow(0, 3000);
		cout << "Case #" << tcase << ": " << n - res << endl;
	}
	return 0;
}