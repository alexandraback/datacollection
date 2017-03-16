#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

const long long mod = 1000000007;

int adj[26][26];
int visited[26];
long long f[200];
int ind[26];

void precalc() {
    f[1] = 1;
    for (int i = 2; i < 200; ++i) {
        f[i] = (f[i - 1] * i) % mod;
    }
}

void add(string& t) {
    int flag = 0;
    for (int i = 1; i < sz(t); ++i) {
        if (t[i - 1] != t[i]) {
            flag = 1;
            adj[t[i - 1] - 'a'][t[i] - 'a']++;
        }
    }
    if (!flag) {
        adj[t[0] - 'a'][t[0] - 'a']++;
    }
}

int isValid() {
    int a[26][26] = {0};
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            a[i][j] = adj[i][j];
            if (i != j && adj[i][j] > 1) {
                return 0;
            }
        }
    }
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (a[i][k] && a[k][j]) {
                    a[i][j] = 1;
                }
                if (i != j && a[i][j] && a[j][i]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

long long dfs(int u) {
    long long ret = 1;
    visited[u] = 1;
    int cnt = 0;
    for (int v = 0; v < 26; ++v) {
        if (!visited[v] && adj[u][v]) {
            ret = (ret * dfs(v)) % mod;
            if (++cnt >= 2) {
                return 0;
            }
        }
    }
    if (adj[u][u]) {
        ret = (ret * f[adj[u][u]]) % mod;
    }
    return ret;
}

int main() {
    precalc();

    int T;
    int n;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ", cs);
        scanf("%d", &n);
        fill(adj[0], adj[26], 0);
        fill(visited, visited + 26, 0);
        fill(ind, ind + 26, 0);

        for (int i = 0; i < n; ++i) {
            char tmp[200];
            scanf("%s", tmp);
            string t = tmp;
            add(t);
        }
        if (!isValid()) {
            printf("0\n");
        } else {
            long long ans = 1;

            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (i != j && adj[i][j]) {
                        ind[j]++;
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < 26; ++i) {
                int out = 0;
                for (int j = 0; j < 26; ++j) {
                    out += adj[i][j];
                }
                if (out == 0) {
                    continue;
                }
                if (!visited[i] && ind[i] == 0) {
                    ans = (ans * dfs(i)) % mod;
                    cnt++;
                }
            }
            ans = (ans * f[cnt]) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}


