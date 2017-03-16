#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 1010

using namespace std;

int n,f[MAXN];
int cyclen[MAXN];
vector<int> ch[MAXN];

int dfs(int u, int prv) {
    int dep = 0;
    for (int v : ch[u]) {
        if (v == prv) continue;
        dep = max(dep, dfs(v, u));
    }
    return dep + 1;
}

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> n;
        for (int i = 1; i <= n; i++) ch[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
            ch[f[i]].push_back(i);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cyclen[i] = 0;
            int j = i;
            int t = 1;
            while (t <= n) {
                j = f[j];
                if (i == j) {
                    cyclen[i] = t;
                    break;
                }
                t++;
            }
            ans = max(ans, cyclen[i]);
        }

        int ans2 = 0;

        for (int i = 1; i <= n; i++) {
            if (cyclen[i] != 2) continue;
            int j = f[i];
            if (j < i) continue;
            ans2 += dfs(i,j) + dfs(j,i);
        }

        ans = max(ans, ans2);

        cout << "Case #" << TC << ": ";
        cout << ans << '\n';
    }
}
