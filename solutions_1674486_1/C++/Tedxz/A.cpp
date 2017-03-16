#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

int T, n, deg[1100];
bool vis[1100], flag;
struct Edge
{
    int t;
    Edge *nxt;
    Edge() {}
    Edge(const int &_t, Edge *_nxt) :
        t(_t), nxt(_nxt) {}
}EdgePool[3000000], *ptr = EdgePool, *head[1100];

inline void AddEdge(const int &u, const int &v)
{
    head[u] = new (ptr++) Edge(v, head[u]);
//    head[v] = new (ptr++) Edge(u, head[v]);
}

void dfs(int now) {
    if (vis[now])
        flag = true;
    if (flag)
        return;
    vis[now] = true;
    for (Edge *p = head[now]; p; p = p->nxt) {
        dfs(p->t);
        if (flag) break;
    }
}

void solve() {
    ptr = EdgePool;
    memset(head, 0, sizeof head);
    memset(EdgePool, 0, sizeof EdgePool);
    cin >> n;
    for (int i = 1, j, x; i <= n; ++i) {
        cin >> deg[i];
        j = deg[i];
        while (j--) {
            cin >> x;
            AddEdge(i, x);
        }
    }

    flag = false;
    for (int i = 1; i <= n; ++i) {
        if (flag) break;
        memset(vis, false, sizeof vis);        
//        if (deg[i] == 0)
            dfs(i);
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }

}
