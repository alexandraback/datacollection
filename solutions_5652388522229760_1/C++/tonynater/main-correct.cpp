#include <bits/stdc++.h>
using namespace std;

bool vis[10];
int n;

bool done() {
    for (int i = 0; i < 10; i++) {
        if (!vis[i]) {
            return false;
        }
    }
    return true;
}

void process(long long x) {
    while (x > 0) {
        vis[x % 10] = true;
        x /= 10;
    }
}

void solve() {
    cin >> n;
    if (n == 0) {
        cout << "INSOMNIA";
        return;
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; ; i++) {
        process(i * n);
        if (done()) {
            cout << i * n;
            return;
        }
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
        cout << '\n';
    }
    return 0;
}
