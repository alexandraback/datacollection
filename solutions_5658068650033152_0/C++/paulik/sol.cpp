#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dirs[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int to_index(int i, int j, int m) {
    return i * m + j;
}

bool used(int i, int j, int m, int mask) {
    return mask & (1 << to_index(i, j, m));
}

bool use(int i, int j, int m, int &mask) {
    mask |= (1 << to_index(i, j, m));
}

int bfs(int mask, int n, int m) {
    queue< pair<int, int> > q;
    int visited = 0;
    for (int i = 0; i < n; ++i) {
        if (!used(i, 0, m, mask)) {
            q.push(make_pair(i, 0));
            use(i, 0, m, visited);
        }
        if (!used(i, m - 1, m, mask)) {
            q.push(make_pair(i, m - 1));
            use(i, m - 1, m, visited);
        }
    }
    for (int j = 0; j < m; ++j) {
        if (!used(0, j, m, mask)) {
            q.push(make_pair(0, j));
            use(0, j, m, visited);
        }
        if (!used(n - 1, j, m, mask)) {
            q.push(make_pair(n - 1, j));
            use(n - 1, j, m, visited);
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pair<int, int> new_p(p.first + dirs[i][0], p.second + dirs[i][1]);
            if (new_p.first < 0 || new_p.second < 0 || new_p.first >= n || new_p.second >= m)
                continue;
            if (!used(new_p.first, new_p.second, m, visited) && !used(new_p.first, new_p.second, m, mask)) {
                use(new_p.first, new_p.second, m, visited);
                q.push(new_p);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!used(i, j, m, visited))
                ++ans;
    return ans;
}

int solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int max_mask = 1 << (n * m);

    int best = 100500;
    for (int mask = 0; mask < max_mask; ++mask) {
        int cnt = bfs(mask, n, m);
        if (cnt < k) continue;
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (used(i, j, m, mask))
                    ++ans;
        best = min(best, ans);
    }
    return best;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}

