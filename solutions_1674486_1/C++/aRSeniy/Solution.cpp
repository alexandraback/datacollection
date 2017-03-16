#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

long long visited[2012];
vector < vector <int> > g;

void dfs (int v, int parent) {
    if (parent == -1)
        ++visited[v];
    else
        visited[v] += visited[parent];

    if (visited[v] > 1)
        return;

    for (int i = 0; i < g[v].size(); ++i)
        dfs(g[v][i], v);
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
        int n;
		cin >> n;

        g.assign(n, vector <int> (0));
        
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int t;
                cin >> t;
                g[i].push_back(t - 1);
            }
        }

        string ans;

        bool got = false;
        for (int x = 0; x < n; ++x) {
            for (int i = 0; i < n; ++i) {
                visited[i] = 0;
            }
            dfs(x, -1);
            for (int i = 0; i < n; ++i) {
                if (visited[i] < 0)
                    cerr << "overflow" << endl;
                if (visited[i] > 1) {
                    ans = "Yes";
                    got = true;
                    break;
                }
            }
            if (got)
                break;
        }
        if (!got)
            ans = "No";
		
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}