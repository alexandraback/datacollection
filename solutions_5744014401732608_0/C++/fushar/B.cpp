#include <bits/stdc++.h>
using namespace std;

int T;
int N, M;
int G[6][6];
int H[6][6];

int CNT;
bool seen[6];

void dfs(int u) {
    if (CNT > M) {
        return;
    }
    if (u == N-1) {
        CNT++;
        return;
    }

    seen[u] = true;
    for (int v = 0; v < N; v++) {

        if (G[u][v] && !seen[v]) {
            dfs(v);
        }
    }
    seen[u] = false;
}

bool has_cycles() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            H[i][j] = G[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                H[i][j] |= H[i][k] & H[k][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (H[i][i]) {
            return true;
        }
    }
    return false;
}

bool can(int r, int c) {
    if (c == N) {
        return can(r+1, 0);
    }
    if (r == N) {
        if (has_cycles()) {
            return false;
        }
        CNT = 0;
        memset(seen, 0, sizeof seen);
        dfs(0);
        return CNT == M;
    }

    G[r][c] = 0;
    if (can(r, c+1)) {
        return true;
    }
    if (r != c && r != N-1 && G[c][r] != 1) {
        G[r][c] = 1;
        if (can(r, c+1)) {
            return true;
        }
    }
    G[r][c] = -1;
    return false;
}

void solve() {
    memset(G, -1, sizeof G);
    if (can(0, 0)) {
        cout << "POSSIBLE" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << G[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        cout << "Case #" << tc << ": ";
        solve();
    }
}
