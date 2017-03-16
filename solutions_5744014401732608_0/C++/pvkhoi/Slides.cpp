#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) int(a.size())

typedef long long ll;

bool adj[55][55];
ll B, M;

vector <bool> toBinary(ll M) {
    vector <bool> res;
    while (M) {
        res.pb(M & 1);
        M >>= 1;
    }
    return res;
}

void fullGraph(int n) {
    for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++) adj[i][j] = 1;
}

void solve(vector <bool> np) {
    if (M > (1 << (B-2))) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << "POSSIBLE\n";
    int n = sz(np) + 1;
    fullGraph(n);
    if (n < B) adj[n][B] = 1;
    for (int i = 0; i < n-2; i++) {
        if (!np[i]) continue;
        adj[i+2][B] = 1;
    }
    for (int i = 1; i <= B; i++) {
        for (int j = 1; j <= B; j++)
            if (adj[i][j]) cout << 1;
            else cout << 0;
        cout << endl;
    }
}

void rset() {
    memset(adj, 0, sizeof adj);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        rset();
        cin >> B >> M;
        vector <bool> np = toBinary(M);
        cout << "Case #" << t << ": ";
        solve(np);
    }
    
    return 0;
}
