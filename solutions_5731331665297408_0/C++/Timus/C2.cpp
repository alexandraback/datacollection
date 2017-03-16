#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> names;
vector<vector<int> > g;
vector<int> used;

bool cmp(int x, int y) {
    return names[x] < names[y];
}

string ans;

void dfs(int v) {
    used[v] = 1;
    ans += names[v];
    for (int i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

bool can(vector<int> p) {
    set<int> z[p.size()];
    int ptr = 0;
    for (int i = 0; i < g[p[0]].size(); ++i)
        z[ptr].insert(g[p[0]][i]);

    for (int i = 1; i < p.size(); ++i) {
        while (ptr >= 0 && z[ptr].find(p[i]) == z[ptr].end())
            --ptr;
        if (ptr < 0)
            return false;
        z[ptr].erase(p[i]);
        ++ptr;
        z[ptr].clear();
        for (int j = 0; j < g[p[i]].size(); ++j)
            z[ptr].insert(g[p[i]][j]);
    }
    return true;
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        names.clear();
        g.clear();
        int n, m;
        cin >> n >> m;
        names.resize(n);
        g.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> names[i];
        for (int i = 0; i < m; ++i) {
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        for (int i = 0; i < n; ++i)
            sort(g[i].begin(), g[i].end(), cmp);

        string bans = "";

        vector<int> p;
        for (int i = 0; i < n; ++i)
            p.push_back(i);
        vector<int> pa = p;
        do {
//            for (int i = 0; i < n; ++i)
//               cerr << p[i] << " ";
//            cerr << can(p) << endl;
            string ans = "";
            for (int i = 0; i < n; ++i)
                ans += names[p[i]];
            if ((bans == "" || ans < bans) && (can(p)))
                bans = ans;
            next_permutation(p.begin(), p.end());
        } while (pa != p);
/*
        for (int i = 0; i < n; ++i) {
            used.clear();
            used.resize(n);
            ans = "";
            dfs(i);
            if (bans == "" || bans > ans)
                bans = ans;
        }
*/
        printf("Case #%d: %s\n", test, bans.c_str());
    }
}
