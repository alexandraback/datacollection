#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;

bool adj[maxn][maxn];
int n;
long long m;

void solve() {
    cin >> n >> m;
    if ((1LL << (n - 2)) < m) {
        cout << "IMPOSSIBLE\n";
        return;
    } else {
        cout << "POSSIBLE\n";
    }

    memset(adj, 0, sizeof(adj));
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            adj[i][j] = true;
        }
    }
    adj[0][n - 1] = true;
    --m;
    for (int i = 0; i < n; i++) {
        if ((m >> i) & 1) {
            adj[0][n - 2 - i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
