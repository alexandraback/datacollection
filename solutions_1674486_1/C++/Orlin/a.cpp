#include <queue>
#include <cstdio>
#include <vector>

using std::vector;

bool cycle(const vector<vector<int> >& graph) {
    const int& n = (int)graph.size();

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);

        std::queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            
            for (int j = 0; j < (int)graph[c].size(); j++) {
                if (visited[graph[c][j]]) return true;
                q.push(graph[c][j]);
                visited[graph[c][j]] = true;
            }
        }
    }

    return false;
}

int main() {
    int ntests;
    std::scanf("%d", &ntests);
    for (int ctest = 1; ctest <= ntests; ctest++) {
        int n;
        std::scanf("%d", &n);
        vector<vector<int> > graph(n);

        for (int i = 0; i < n; i++) {
            int k;
            std::scanf("%d", &k);
            graph[i].resize(k);
            for (int j = 0; j < k; j++) {
                std::scanf("%d", &(graph[i][j]));
                graph[i][j]--;
            }
        }

        std::printf("Case #%d: %s\n", ctest, cycle(graph) ? "Yes" : "No");
    }

    return 0;
}
