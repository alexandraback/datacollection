#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

int n, m;
string strs[10];
vector <int> adj[10];

bool read() {
	if (!(cin >> n >> m))
		return false;
	forn(i, n)
		adj[i].clear();
	forn(i, n)
		cin >> strs[i];
	forn(i, m) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	return true;
}

vector <int> p;
int pos;
bool used[10];

bool has_used_path(int st, int to) {
	queue <int> q;
	vector <bool> inqueue(n);
	q.push(st);
	inqueue[st] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		forn(i, adj[v].size()) {
			int u = adj[v][i];
			if (u == to)
				return true;
			if (!inqueue[u] && used[u])
				inqueue[u] = true, q.push(u);
		}
	}
	return false;
}

void dfs(int v) {
	assert(p[pos] == v);
	pos++;
	used[v] = true;
	bool any = false;
	do {
		any = false;
		forn(i, adj[v].size())
			if (!used[adj[v][i]] && pos < n && adj[v][i] == p[pos]) {
				dfs(adj[v][i]);
				any = true;
			}
	} while (any);
}

void solve() {
	string res = "";
	p.resize(n);
	forn(i, n)
		p[i] = i;
	do {
		forn(i, n)
			used[i] = false;
		
		pos = 0;
		
		dfs(p[0]);
		
		bool has = true;
		forn(i, n)
			if (!used[i])
				has = false;
		
		if (has) {
			string nres = "";
			forn(i, n)
				nres += strs[p[i]];
			if (res == "" || res > nres)
				res = nres;
		}
	} while (next_permutation(all(p)));
	cout << res;
}

int main() {
#ifdef dans
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
	freopen(TASK_NAME ".in", "r", stdin);
	freopen(TASK_NAME ".out", "w", stdout);
#endif
	int t;
	cin >> t;
	int test = 0;
	while (read()) {
		test++;
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	
	return 0;
}
