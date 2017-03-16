#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

const int MAX_N = 50, MAX_M = 5000;

long long ans = 0;
int T;

int n, m, sp, stack[MAX_N], zc[MAX_N];

struct Edge {
    int t;
    Edge *nxt;
    Edge() {}
    Edge(int x, Edge *i) :t(x), nxt(i){}
}*head[MAX_N], EdgePool[MAX_M], *ptr;

void addEdge(int u, int v) {
    head[u] = new (ptr++) Edge(v, head[u]);
    head[v] = new (ptr++) Edge(u, head[v]);
    
}
bool vis[MAX_N];
void DFS(int x) {
    stack[sp++] = x;
    vis[x] = 1;
    vector<pair<int, Edge*> > sl;
    for (Edge *p = head[x]; p; p = p->nxt) {
        sl.push_back(make_pair(zc[p->t], p));
    }
    sort(sl.begin(), sl.end());
    for (int i = 0; i < sl.size(); ++i) {
        if (!vis[sl[i].second->t])
            DFS(sl[i].second->t);
    }
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> n >> m;
        memset(head, 0, sizeof head);
        ptr = EdgePool;
        int maxz = 99999, st;
        for (int i = 1; i <= n; ++i) {
            cin >> zc[i];
            if (zc[i] < maxz) {
                maxz = zc[i];
                st = i;
            }
        }
        for (int u, v, i = 0; i < m; ++i) {
            cin >> u >> v;
            addEdge(u, v);
        }
        sp = 0;
        memset(vis, 0, sizeof vis);
        DFS(st);
        printf("Case #%d: ", cs);
        for (int i = 0; i < n; ++i) {
            printf("%d", zc[stack[i]]);
        }
        printf("\n");
    }
    return 0;
}
