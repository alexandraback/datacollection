#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int f[N], deg[N], d[N];

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
            d[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
            deg[f[i]]++;
        }
        set<pair<int,int>> ds;
        ds.clear();
        for (int i = 1; i <= n; i++) ds.insert({deg[i],i});
        int ans = 1;
        while (1) {
            int u = ds.begin()->second;
            if (deg[u] > 0) break;
            ds.erase(ds.begin());
            int v = f[u];
            d[v] = max(d[v], d[u]+1);
            ds.erase({deg[f[u]],f[u]});
            deg[f[u]]--;
            ds.insert({deg[f[u]],f[u]});
        }
        for (int i = 1; i <= n; i++)
        if (deg[i] == 1) {
            int res = 0;
            vector<int> ds;
            ds.clear();
            int u = i;
            do {
                ds.push_back(u);
                deg[u] = 0;
                u = f[u];
            } while (u != i);
            res = ds.size();
            if (ds.size() == 2) {
                res = max(res, d[i]+d[f[i]]);
            }
            ans = max(ans, res);
        }
        cout << "Case #" << nt << ": " << ans << '\n';
    }
    return 0;
}
