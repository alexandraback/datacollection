#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000000 + 10;
const int INF = (int)(1e9);
const int MOD = (int)(1e9) + 7;

int f[MAXN];
int n;

int solve() {
    int n;
    cin >> n;
    return f[n];
}

bool valid(int x) {
    return ((1 <= x) && (x <= n));
}

int reverse(int x) {
    vector<int> d;
    while (x > 0) {
        d.push_back(x % 10); x = x / 10;
    }
    int res = 0;
    for(int i = 0; i < d.size(); i++) res = res * 10 + d[i];
    return res;
}

void init() {
    n = 10000000 - 1;
    for(int i = 1; i <= n; i++) f[i] = INF;
    f[1] = 1;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (valid(u + 1) && (f[u + 1] == INF)) {
            f[u + 1] = f[u] + 1;
            Q.push(u + 1);
        }
        int v = reverse(u);
        if (valid(v) && (f[v] == INF)) {
            f[v] = f[u] + 1;
            Q.push(v);
        }
    }
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);

    init();
    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}
