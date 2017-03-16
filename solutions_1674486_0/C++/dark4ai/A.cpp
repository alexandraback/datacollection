#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

vector<vector<int> > g;
vector<bool> used;
bool find0 = false;
int n;

void dfs(int v) {
    if(find0) return;
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(!used[u]) {
            dfs(u);
        } else {
            find0 = true;
            return;
        }
    }
}

void solve() {
    g.clear();
    cin >> n;
    used.resize(n);
    g.resize(n);
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            x--;
            g[i].push_back(x);
        }
    }
    for(int i = 0; i < n; i++) {
        used.assign(n, false);
        find0 = false;
        dfs(i);
        if(find0) {
            cout << " Yes" << endl;        
            return;
        }
    }
    cout << " No" << endl;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":";
        solve();
    }
    return 0;
}
