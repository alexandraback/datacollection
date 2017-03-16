#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1005;
int n, bff[N];
bool vst[N];
vector<int> e[N];

int max_circle() {
    vector<int> ind(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) ++ind[bff[i]];
    for (int i = 0; i < n; ++i) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (!--ind[bff[x]]) q.push(bff[x]);
    }
    int res = 1;
    for (int i = 0; i < n; ++i) if (ind[i]) {
        int l = 1;
        for (int x = bff[i]; x != i; x = bff[x]) ++l, ind[x] = 0;
        res = max(res, l);
    }
    return res;
}

int dfs(int x, int d) {
    vst[x] = true;
    int res = d;
    for (auto &y: e[x]) if (!vst[y]) {
        res = max(res, dfs(y, d + 1));
    }
    return res;
}

int gao(int x) {
    fill_n(vst, n, false);
    int y = bff[x];
    vst[x] = vst[y] = true;
    return dfs(x, 1) + dfs(y, 1);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) e[i].clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", bff + i), --bff[i];
            e[bff[i]].push_back(i);
        }
        int ans = max_circle();
        int res = 0;
        for (int i = 0; i < n; ++i) if (bff[i] < i && bff[bff[i]] == i) {
            res += gao(i);
        }
        ans = max(ans, res);
        printf("Case #%d: %d\n", cas, ans);
    }
}
