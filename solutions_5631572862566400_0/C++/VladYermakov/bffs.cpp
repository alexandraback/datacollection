#include <bits/stdc++.h>

using namespace std;

int f[2001], n, res = 0;
int used[2001];
vector < int > ans;

bool ok(int len) {
    for (int i = 0; i < len; ++i) {
        int next = (i + 1) % len;
        int prev = (i - 1 + len) % len;
        if (f[ans[i]] != ans[next] && f[ans[i]] != ans[prev]) {
            return false;
        }
    }
    return true;
}

void dfs(int d = 0) {
    if (d == n) {
        for (int i = 0; i < n; ++i) {
            if (ok(i + 1)) res = max(res, i + 1);
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ans.push_back(i);
            used[i] = true;
            dfs(d + 1);
            used[i] = false;
            ans.pop_back();
        }
    }
}

main () {

    freopen ("C-small.in", "r", stdin);
    freopen ("c.out", "w", stdout);

    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {
        cout << "Case #" << num <<  ": ";
        cin >> n;
        ans.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> f[i];
        }
        for (int i = 1; i <= n; ++i) used[i] = false;
        res = 0;
        dfs();
        cout << res << "\n";
    }
}
