#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

const int N = 50 + 10;
const int MOD = 1000000000 + 7;

int n, m;
vector<int> adj[N];
vector< pair<int, int> > edges;
int zip[N];
int color[N];
int father[N];
int f[N];

int getf(int u)
{
    return u == f[u] ? u : f[u] = getf(f[u]);
}

int isConnect()
{
    int tot = 0;
    for(int i = 0; i < n; ++ i) {
        if (color[i] != 2) ++ tot;
        f[i] = i;
    }
    for(int i = 0; i < edges.size(); ++ i) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (color[u] == 2 || color[v] == 2) continue;
        if (getf(u) != getf(v)) {
            -- tot;
            f[f[u]] = f[v];
        }
    }
    return tot == 1;
}

void solve()
{
    cin >> n >> m;
    int st = 0;
    edges.clear();
    for(int i = 0; i < n; ++ i) {
        cin >> zip[i];
        if (zip[i] < zip[st]) {
            st = i;
        }
        color[i] = 0;
        adj[i].clear();
    }
    int u, v;
    for(int i = 0; i < m; ++ i) {
        scanf("%d%d", &u, &v);
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back(make_pair(u, v));
    }
    
    color[st] = 1;
    father[st] = -1;
    vector<int> ret;
    ret.push_back(st);
    int cur = st;
    for(int tt = 2; tt <= n; ++ tt) {
        vector<int> tmp;
        int v, w;
        int minv, minw = -1;
        for(v = cur; v != -1; v = father[v]) {
            foreach(it, adj[v]) {
                w = *it;
                if (color[w] == 0) {
                    if (minw < 0) {
                        minw = w;
                        minv = v;
                    } else {
                        if (zip[minw] > zip[w]) {
                            minw = w;
                            minv = v;
                        }
                    }
                }
            }
            tmp.push_back(v);
            color[v] = 2;
            if (! isConnect()) {
                break;
            }
        }
        foreach(it, tmp) {
            v = *it;
            color[v] = 1;
        }
        for(v = cur; v != minv; v = father[v]) {
            color[v] = 2;
        }
        color[minw] = 1;
        father[minw] = minv;
        cur = minw;
        ret.push_back(cur);
    }

    for(int i = 0; i < n; ++ i) {
        printf("%05d", zip[ret[i]]);
    }
    cout << endl;
}

int main()
{
    int test; cin >> test;
    for(int i = 1; i <= test; ++ i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}