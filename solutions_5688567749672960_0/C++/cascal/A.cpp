#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;

using namespace std;

int reverse(int n) {
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int bfs(int target) {
    queue<int> q;
    vector<bool> v(1000001, false);
    v[1] = true;
    q.push(1);
    q.push(1);
    while (!q.empty()) {
        int n = q.front(); q.pop();
        int s = q.front(); q.pop();
        if (n == target) return s;
        if (n + 1 <= target && !v[n + 1]) {
            q.push(n + 1);
            q.push(s + 1);
            v[n + 1] = true;
        }
        int r = reverse(n);
        if (r <= target && !v[r]) {
            q.push(r);
            q.push(s + 1);
            v[r] = true;
        }
    }
}

int main() {
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << bfs(n) << endl;
    }
    return 0;
}
