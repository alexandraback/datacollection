#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

const int N = 50;

int n, m, order[N];
bool graph[N][N], used[N], bad[N], visited[N];
std::string codes[N];

bool by_code(int i, int j) {
    return codes[i] < codes[j];
}

void dfs(int u) {
    if (!visited[u]) {
        visited[u] = true;
        for (int v = 0; v < n; ++ v) {
            if (!bad[v] && graph[u][v]) {
                dfs(v);
            }
        }
    }
}

bool check(std::vector <int> order) {
    std::vector <int> stack(1, order[0]);
    memset(bad, 0, sizeof(bad));
    for (int i = 1; i < (int)order.size(); ++ i) {
        int v = order[i];
        while (!stack.empty() && !graph[stack.back()][v]) {
            bad[stack.back()] = true;
            stack.pop_back();
        }
        if (stack.empty()) {
            return false;
        }
        stack.push_back(v);
    }
    memset(visited, 0, sizeof(visited));
    dfs(order[0]);
    for (int i = 0; i < n; ++ i) {
        if (!used[i] && !visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int test_count;
    scanf("%d", &test_count);
    for (int t = 1; t <= test_count; ++ t) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++ i) {
            static char buffer[6];
            scanf("%s", buffer);
            codes[i] = buffer;
            order[i] = i;
        }
        std::sort(order, order + n, by_code);
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < m; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            graph[a][b] = graph[b][a] = true;
        }
        std::vector <int> prefix;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (!used[order[j]]) {
                    std::vector <int> newPrefix(prefix);
                    newPrefix.push_back(order[j]);
                    used[order[j]] = true;
                    if (check(newPrefix)) {
                        prefix = newPrefix;
                        break;
                    }
                    used[order[j]] = false;
                }
            }
        }
        std::string result;
        for (int i : prefix) {
            result += codes[i];
        }
        printf("Case #%d: %s\n", t, result.c_str());
    }
    return 0;
}
