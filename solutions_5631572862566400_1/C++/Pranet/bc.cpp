//Pranet Verma
#include <bits/stdc++.h>
using namespace std;
int vis[1001], tim[1001];
int g[1001], sz, A, B;
vector<int> rg[1001];
void dfs(int u, int d) {
    tim[u] = d;
    vis[u] = 1;
    int v = g[u];
    if (vis[v] == 0) {
        dfs(v, d + 1);
    }
    else if (vis[v] == 1) {
        sz = tim[u] - tim[v] + 1;
        A = u;
        B = v;
    }
    vis[u] = 2;
}
int dep(int u, int p) {
    int ret = 1;
    for (auto v : rg[u]) {
        if (v != p) {
            ret =  max(ret, 1 + dep(v, u));
        }
    }
    return ret;
}
int main() {
    int t;
    cin>>t;
    for (int tc = 1; tc <= t; ++tc) {
        cout<<"Case #"<<tc<<": ";
        int n;
        cin>>n;
        for (int i = 1; i <= n; ++i) {
            rg[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            cin>>g[i];
            rg[g[i]].push_back(i);
        }
        int ans = 0, other = 0;
        memset(vis, 0, sizeof vis);
        vector<int> avail;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0) {
                sz = 0;
                dfs(i, 0);
                assert (sz != 1);
                if (sz == 0) {
                    continue;
                }
                if (sz == 2) {
                    other += dep(A, B) + dep(B, A);
                }
                else {
                    ans = max(ans, sz);
                }
            }
        }
        ans = max(ans, other);
        cout<<ans<<"\n";
    }
}