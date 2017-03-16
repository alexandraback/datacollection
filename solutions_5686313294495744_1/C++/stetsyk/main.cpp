#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#ifdef lyosha
#define files freopen("input.txt", "r", stdin);
#else
#define files //freopen("howmany.in","r",stdin); freopen("howmany.out","w",sdout);
#endif
using namespace std;
typedef long long ll;
#define y1 fjlwekf
const ll mod = 1e9 + 7;
const int N = 2025;
const int INF = 10000;
struct edge {
	int a, b, cap, flow;
};

int  s, t, d[N], ptr[N], q[N];
vector<edge> e;
vector<int> g[N];
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, N * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, N * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}
int n;
string ss[N][2];
int a[N][2];
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    ll T;
    cin >> T;
    for(ll qw = 1; qw <= T; ++qw)
    {
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> ss[i][0] >> ss[i][1];
        }
        map<string, int> mp1;
        map<string, int> mp2;
        for(int i = 0; i < n; ++i){
            if(mp1.count(ss[i][0])){
                a[i][0] = mp1[ss[i][0]];
            }
            else{
                a[i][0] = mp1.size();
                mp1[ss[i][0]] = a[i][0];
            }
            if(mp2.count(ss[i][1])){
                a[i][1] = mp2[ss[i][1]];
            }
            else{
                a[i][1] = mp2.size();
                mp2[ss[i][1]] = a[i][1];
            }
        }
        int ans = mp1.size() + mp2.size();
        e.clear();
        for(int i = 0; i < N; ++i){
            g[i].clear();
        }
        s = 0;
        t = N - 1;
        for(int i = 0; i < n; ++i){
            add_edge(a[i][0] + 1, a[i][1] + 1001, 1);
        }
        for(int i = 1; i <= 1000; ++i){
            add_edge(s, i, 1);
        }
        for(int i = 1001; i <= 2000; ++i){
            add_edge(i, t, 1);
        }
        ans -= dinic();
        ans = n - ans;
        cout << "Case #" << qw << ": " << ans << "\n";
    }
    return 0;
}
