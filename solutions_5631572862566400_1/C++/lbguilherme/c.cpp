#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> cometo;
vector<int> path;
bool visited[10000];

int dfs(int i);

int sidesize(int i) {
    memset(visited, 0, sizeof(visited));
    return dfs(i);
}

int dfs(int i) {
    if (visited[i])
        return 0;
    visited[i] = true;

    path[i] = 0;
    for (auto j : cometo[i]) {
        path[i] = max(path[i], 1 + dfs(j));
    }
    return path[i];
}

void solve() {
    cin >> n;
    int bff[n];
    vector<int> kids(n);
    for (int i = 0; i < n; ++i) {
        kids[i] = i;
        cin >> bff[i];
        bff[i] -= 1;
    }

    int cyclesize = 1;
    for (int i = 0; i < n; ++i) {
        int x = i;
        for (int j = 0; j < n; ++j) {
            x = bff[x];
            if (x == i) {
                cyclesize = max(cyclesize, j + 1);
                break;
            }
        }
    }

    cometo.clear();
    cometo.resize(n);
    path.clear();
    path.resize(n);
    for (int i = 0; i < n; ++i) {
        cometo[bff[i]].push_back(i);
    }

    int extra = 0;
    for (int i = 0; i < n; ++i) {
        if (bff[bff[i]] == i && i < bff[i]) {
            extra += 2;
            cometo[i].erase(find(cometo[i].begin(), cometo[i].end(), bff[i]));
            cometo[bff[i]].erase(find(cometo[bff[i]].begin(), cometo[bff[i]].end(), i));
            extra += sidesize(i);
            extra += sidesize(bff[i]);
        }
    }
    int best = max(cyclesize, extra);
    cout << best << endl;

    // int best = 1;
    // do {
    //     for (int sz = best + 1; sz <= n; ++sz) {
    //         bool valid = true;
    //         for (int i = 0; i < sz; ++i) {
    //             int b = bff[kids[i]];
    //             if (kids[(i + 1) % sz] != b && kids[(sz + i - 1) % sz] != b) {
    //                 valid = false;
    //                 break;
    //             }
    //         }
    //         if (valid) {
    //             best = max(best, sz);
    //         }
    //     }
    // } while (next_permutation(kids.begin(), kids.end()));
    // cout << best << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
