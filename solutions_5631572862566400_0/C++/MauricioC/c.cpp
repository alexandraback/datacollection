#include <cassert>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> edges[1001];
int a, b;

int dfs(int v) {
    int ans = 1;
    for (int i = 0; i < edges[v].size(); i++) {
        int w = edges[v][i];
        if (w == a || w == b)
            continue;
        ans = max(ans, 1 + dfs(w));
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int z = 1; z <= t; z++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            edges[i].clear();

        int bff[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &bff[i]);
            bff[i]--;
            edges[bff[i]].push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (bff[bff[i]] == i && i < bff[i]) {
                a = i;
                b = bff[i];
                ans += dfs(a) + dfs(b);
            }

        for (int i = 0; i < n; i++) {
            bool visited[n];
            memset(visited, 0, sizeof visited);

            int cur = i, len = 0;
            while (!visited[cur]) {
                visited[cur] = true;
                cur = bff[cur];
                len++;
            }

            if (cur == i)
                ans = max(ans, len);
        }

        printf("Case #%d: %d\n", z, ans);
    }
}
