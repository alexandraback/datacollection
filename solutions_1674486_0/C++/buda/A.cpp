#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

bool vis[1000];
bool dfs(int u, const vector< vector<int> > &G) {
    if (vis[u]) {
        return true;
    }
    vis[u] = 1;
    for (int i=0; i<(int)G[u].size(); ++i) {
        if (dfs(G[u][i], G)) {
            return true;
        }
    }
    return false;
}
int main() {
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int n;
        cin >> n;
        vector< vector<int> > G(n, vector<int>());
        for (int i=0; i<n; ++i) {
            int m;
            int from;
            cin >> m;
            for (int j=0; j<m; ++j) {
                cin >> from;
                G[i].push_back(from-1);
            }
        }
        bool yes = false;
        for (int i=0; i<n; ++i) {
            memset(vis, 0, sizeof vis);
            for (int j=0; j<(int)G[i].size(); ++j) {
                if (dfs(G[i][j], G)) {
                    yes = true;
                    goto DONE;
                }
            }
        }
        DONE:;
        cout << "Case #" << t << ": " << (yes ? "Yes" : "No") << '\n';
    }
	return 0;
}
