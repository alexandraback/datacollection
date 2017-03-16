#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;

const int maxN = 1010;

vector<int> G[maxN];

bool visited[maxN];

int F[maxN];

const int INF = 10000000;

int start;

int dfs(int x, int parent) {
    visited[x] = true;
    if (!visited[F[x]]) return 1 + dfs(F[x], x);
    if (F[x] != parent) {
        if (F[x] == start) return 1;
        return -INF;
    }

    int ret = 0;
    for (int i = 0; i < G[x].size(); ++ i) {
        int y = G[x][i];
        if (!visited[y]) {
            ret = max(ret, 1 + dfs(y, x));
        }
    }
    return ret;
}

void solve() {
    int ret = -1;
    for (start = 1; start <= N; ++ start) {
        memset(visited, false, sizeof(visited));
        int K = dfs(start, -1);
        ret = max(ret, K);
    }
    printf("%d\n", ret);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++ i)
            G[i].clear();
        for (int i = 1; i <= N; ++ i) {
            scanf("%d", &F[i]);
            bool flag = true;
            for (int j = 0; j < G[i].size(); ++ j)
                if (G[i][j] == F[i]) {
                    flag = false;
                    break;
                }
            if (flag) {
                G[i].push_back(F[i]);
                G[F[i]].push_back(i);
            }
        }
        printf("Case #%d: ", test);
        solve();
    }
    return 0;
}
