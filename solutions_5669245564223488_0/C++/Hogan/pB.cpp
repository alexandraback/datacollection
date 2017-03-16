#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char con[10][110];
vector<int> v[10];
bool vis[10];
bool c[26];

int n;

int dfs(int t, int last) {
    if (t == n) {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = true;

            bool tmp[26];
            for (int j = 0; j < 26; j++) {
                tmp[j] = c[j];
            }

            int nlast = -1;
            bool suc = true;
            for (int j = 0; j < (int)v[i].size(); j++) {
                if (j == 0) {
                    if (last != -1 && last != v[i][j] && c[v[i][j]]) {
                        suc = false;
                        break;
                    }
                }
                else if (c[v[i][j]]) {
                    suc = false;
                    break;
                }

                c[v[i][j]] = true;
                nlast = v[i][j];
            }

            if (suc) ans += dfs(t + 1, nlast);
            for (int j = 0; j < 26; j++) {
                c[j] = tmp[j];
            }

            vis[i] = false;
        }
    }
    return ans;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int times = 0; times < T; times++) {
        memset(vis, 0, sizeof(vis));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < 10; i++) {
            v[i] = vector<int>();
        }

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", con[i]);
            int len = strlen(con[i]);

            int f = con[i][0] - 'a';
            for (int j = 0; j < len; j++) {
                if (con[i][j] - 'a' != f) {
                    v[i].push_back(f);
                    f = con[i][j] - 'a';
                }
            }
            v[i].push_back(f);
        }

        int ans = dfs(0, -1);
        printf("Case #%d: %d\n", times + 1, ans);
    }
}
