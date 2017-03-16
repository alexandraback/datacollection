#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        int n;
        scanf("%d", &n);
        std::vector<std::string> a(n), b(n);
        for (int i = 0; i < n; ++ i) {
            std::cin >> a[i] >> b[i];
        }
        std::map<std::string, int> ma, mb;
        for (int i = 0; i < n; ++ i) {
            ma[a[i]] = 0;
            mb[b[i]] = 0;
        }
        int x = 0;
        int y = 0;
        for (auto& iterator : ma) {
            iterator.second = x ++;
        }
        for (auto& iterator : mb) {
            iterator.second = y ++;
        }
        std::vector<std::vector<int>> graph(x);
        for (int i = 0; i < n; ++ i) {
            graph[ma.at(a[i])].push_back(mb.at(b[i]));
        }
        std::vector<bool> visited(x);
        std::vector<int> match(y, -1);
        std::function<bool(int)> find = [&](int u)
        {
            if (visited[u]) {
                return false;
            }
            visited[u] = true;
            for (int v : graph[u]) {
                if (!~match[v] || find(match[v])) {
                    match[v] = u;
                    return true;
                }
            }
            return false;
        };
        int result = n - x - y;
        for (int i = 0; i < x; ++ i) {
            if (find(i)) {
                result ++;
                std::fill(visited.begin(), visited.end(), false);
            }
        }
        printf("Case #%d: %d\n", t, result);
    }
}
