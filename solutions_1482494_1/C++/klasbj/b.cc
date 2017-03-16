#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

#define MAX 1000

bool used[2][MAX];
int N;
vector<pii> xs(MAX);

bool sorter(const pii & a, const pii & b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int dfs(int ngames = 0, int stars = 0) {
    // check if there is a result
    bool any_unsolved = false;
    if (ngames >= N) {
        for (int i = 0; i < N && !any_unsolved; ++i)
            any_unsolved = !used[1][i];
        if (!any_unsolved) {
            // puzzle is solved
            return ngames;
        }
    }
    if (ngames > 2*N) return 0;

    // greedily pick a two-star if possible (doesn't matter which one...)
    for (int i = 0; i < N; ++i) {
        if (!used[0][i] && !used[1][i]) {
            if (stars >= xs[i].second) {
                used[0][i] = true;
                used[1][i] = true;
                return dfs(ngames+1, stars+2);
            }
        }
    }
    // otherwise pick a difficult one
    for (int i = 0; i < N; ++i) {
        if (!used[1][i]) {
            if (stars >= xs[i].second) {
                used[1][i] = true;
                return dfs(ngames+1, stars+1);
            }
        }
    }
    // otherwise pick a one-star
    for (int i = 0; i < N; ++i) {
        if (!used[0][i]) {
            if (stars >= xs[i].first) {
                used[0][i] = true;
                return dfs(ngames+1, stars+1);
            }
        }
    }
    return 0;
}

void solve(int tc) {
    memset(used, 0, sizeof used);
    int ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> xs[i].first >> xs[i].second;

    sort(xs.begin(), xs.begin()+N, sorter);

    ans = dfs();

    if (ans == 0)
        cout << "Case #" << tc << ": " << "Too Bad\n";
    else
        cout << "Case #" << tc << ": " << ans << "\n";
}








int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
        solve(t);
    return 0;
}
