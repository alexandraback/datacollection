#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MM = (1 << 20) + 1010;

bool vis[MM];
int keys[1111], n, open[1111];
vector<int> chest[1111], ans;

bool work(int t, int done) {
    if (vis[done]) return false;
        //return res[rem];
    vis[done] = true;
    if (t == n) {
        return true;
    }
    for (int i = 0; i < n; ++i) if (!(done & (1 << i)))   // try pick i
        if (keys[open[i]] > 0) {
            keys[open[i]] --;
            for (size_t j = 0; j < chest[i].size(); ++j)
                keys[chest[i][j]] ++;
            if (work(t + 1, done | (1 << i))) {
                ans.push_back(i);
                return true;
            }
            keys[open[i]] ++;
            for (size_t j = 0; j < chest[i].size(); ++j)
                keys[chest[i][j]] --;
        }
    return false;
}

void solve(int cas) {
    ans.clear();
    int k;
    scanf("%d%d", &k, &n);
    memset(keys, 0, sizeof keys);
    for (int i = 0; i < k; ++i) {
        int x; scanf("%d", &x);
        keys[x] ++;
    }
    for (int i = 0; i <= n; ++i) chest[i].clear();
    for (int i = 0; i < n; ++i) {
        int k; scanf("%d%d", &open[i], &k);
        for (int j = 0; j < k; ++j) {
            int x; scanf("%d", &x);
            chest[i].push_back(x);
        }
    }
    memset(vis, 0, sizeof vis);
    printf("Case #%d:", cas);
    if (work(0, 0)) {
        for (int i = n - 1; i >= 0; --i)
            printf(" %d", ans[i] + 1);
        puts("");
    } else
        puts(" IMPOSSIBLE");
}

int main() {
    freopen("d1.in", "r", stdin);
    freopen("d1.out","w", stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        solve(i);
    return 0;
}
