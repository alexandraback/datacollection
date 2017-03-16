#include <bits/stdc++.h>

using namespace std;

#define MAXN 10001

int L[MAXN], R[MAXN];
bool Viz[MAXN];
vector<int> G[MAXN];
int n, m;
map<string, int> MapL, MapR;

bool match(int i) {
    if(Viz[i]) return false;
    Viz[i] = 1;

    for(auto vec : G[i]) {
        if(!R[vec]) {
            L[i] = vec;
            R[vec] = i;
            return true;
        }
    }

    for(auto vec : G[i]) {
        if(match(R[vec])) {
            L[i] = vec;
            R[vec] = i;
            return true;
        }
    }
    return false;

}


void solve() {
    bool ok = 1;

    while(ok) {
        ok = 0;

        memset(Viz, 0, sizeof(Viz));

        for(int i=1; i<=n; i++) {
            if(!L[i])
                ok |= match(i);
        }
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt) {

        int k;
        cin >> k;
        int kk = k;
        while(k--) {
            string a, b;
            cin >> a >> b;
            if(MapL[a] == 0) MapL[a] = ++n;
            if(MapR[b] == 0) MapR[b] = ++m;

            G[MapL[a]].push_back(MapR[b]);
        }

        solve();
        int sol = 0;
        for(int i = 1; i <= n; ++i)
            if(L[i])
                sol += 1;

        for(int i = 1; i <= n; ++i)
            if(!L[i])
                sol += 1;

        for(int i = 1; i <= m; ++i)
            if(!R[i])
                sol += 1;

        cout << "Case #" << tt << ": " << kk - sol << '\n';

        memset(Viz, 0, sizeof(Viz));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        for(int i = 1; i <= n; ++i)
            G[i].clear();
        MapL.clear();
        MapR.clear();

        n = m = 0;
    }
    return 0;
}
