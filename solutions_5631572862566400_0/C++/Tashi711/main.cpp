#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 1100;

int a[N];
stack<int> s;
int dfn[N];
int low[N];
int dcnt;
bool ins[N];
int blk;
int num[N];
vector<int> adj[N];
int max_circle;
int link;

int calc(int k, int p)
{
	if(adj[k].size() == 0u) {
		return 1;
	}
	int res = 1;
	for(int i = 0; i < (int)adj[k].size(); ++i) {
		if(adj[k][i] == p) {
			continue;
		}
		res = max(res, calc(adj[k][i], p)+1);
	}
	return res;
}

void dfs(int u, int fa)
{
	low[u] = dfn[u] = ++dcnt;
	s.push(u);
	ins[u] = true;
	int v = a[u];
	if(! dfn[v]) {
		dfs(v, u);
		low[u] = min(low[u], low[v]);
	}
	else if(ins[v]) {
		low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		blk++;
		int t;
		int cnt = 0;
		int p1, p2;
		do {
			++cnt;
			t = s. top();
			s. pop();
			p2 = p1;
			p1 = t;
			ins[t] = false;
			num[t] = blk;
		} while(! s. empty() && t != u);
		max_circle = max(max_circle, cnt);
		if(cnt == 2) {
			int f1 = calc(p1, p2);
			int f2 = calc(p2, p1);
			link += f1 + f2;
		}
	}
}


void work()
{
	while(! s.empty()) {
		s.pop();
	}
	dcnt = 0;
	link = 0;
	blk = 0;
	max_circle = 0;
	memset(dfn, 0, sizeof dfn);
	memset(ins, 0, sizeof ins);
	memset(low, 0, sizeof low);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		adj[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; ++i) {
		if(! dfn[i]) {
			dfs(i, -1);
		}
	}
	cout << max(max_circle, link) << endl;
}

int main()
{
	#define LOCAL_
	#ifdef LOCAL
	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout);
	#endif

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cout << "Case #" << i << ": ";
		work();
	}
	return 0;
}
