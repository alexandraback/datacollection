#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 55;
vector<vector<int>> G;
bool done[MAXN];
bool vis[MAXN];
typedef pair<string, int> psi;
int pos[MAXN];
int dfs(int u) {
    assert(!done[u] && !vis[u]);
    vis[u] = 1;
    int ret = 1;
    for (int i=0; i<(int)G[u].size(); ++i) {
        int v = G[u][i];
        if (!done[v] && !vis[v]) {
            ret += dfs(v);
        }
    }
    return ret;
}
string solve() {
    int n, m;
    cin >> n >> m;
    vector<psi> codes(n);
    for (int i=0; i<n; ++i) {
        cin >> codes[i].first;
        codes[i].second = i;
    }
    sort(begin(codes), end(codes));
    for (int i=0; i<n; ++i) {
        pos[codes[i].second] = i;
    }

    G.assign(n, vector<int>());
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    memset(done, 0, sizeof done);
    done[codes[0].second] = 1;
    string sol = codes[0].first;
    vector<int> S(1, codes[0].second);
    int need = n-1;
    while (need > 0) {
        int next = -1;
        int nextpos = n+1;
        int nextsz = n+1;
        /*
        cerr << "stack: ";
        for (int i=0; i<(int)S.size(); ++i) {
            cerr << S[i] << ' ';
        }
        cerr << '\n';
        */
        for (int i=0; i<(int)S.size(); ++i) {
            int u = S[i];
            memset(vis, 0, sizeof vis);
            int reach = 0;
            for (int j=0; j<=i; ++j) {
                int at = S[j];
                for (int k=0; k<(int)G[at].size(); ++k) {
                    int v = G[at][k];
                    if (!done[v] && !vis[v]) {
                        reach += dfs(v);
                    }
                }
            }
            //cerr << "stacksz " << i << " => " << reach << " (need " << need << ")\n";
            if (reach < need) continue;
            for (int j=0; j<(int)G[u].size(); ++j) {
                int v = G[u][j];
                if (!done[v]) {
                    if (pos[v] <= nextpos) {
                        nextpos = pos[v];
                        next = v;
                        nextsz = i+1;
                    }
                }
            }
        }

        assert(next != -1);
        sol += codes[nextpos].first;
        done[next] = 1;
        S.resize(nextsz);
        S.push_back(next);
        --need;
    }
    return sol;
}

int main() {
    int T;
    cin >> T;
    cerr << T << " cases total\n";
    for (int t=1; t<=T; ++t) {
        string sol = solve();
        cout << "Case #" << t << ": " << sol << '\n';
        cerr << "Case #" << t << ": " << sol << '\n';
    }
	return 0;
}
