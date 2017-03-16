#include <bits/stdc++.h>

using namespace std;

int dfs(int v, int step, int f, vector<int> &m, vector<bool> &used) {
    if (f == v) {
        return step;
    } else {
        if (used[v]) {
            return 0;
        }
        used[v] = true;
        int ans = dfs(m[v], step + 1, f, m, used);
        used[v] = false;
        return ans;
    }
}

int dfs1(int v, vector<int> &m, vector<int> &a, vector<bool> &used, vector<int> &d) {
    if (a[v] != 0)
        return a[v];
    if (m[m[v]] == v)
    {
        a[v] = v;
        d[v] = 0;
        return a[v];
    }
    if (used[v]) {
        a[v] = -1;
        return a[v];
    }
    used[v] = true;
    a[v] = dfs1(m[v], m, a, used, d);
    if (a[v] != -1)
        d[v] = d[m[v]] + 1;
    return a[v];
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        int n;
        cin >> n;
        vector<int> m(n);
        vector<int> a(n, 0);
        vector<int> d(n, 0);
        vector<int> sum(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            m[i]--;
        }
        vector<bool> used(n, false);
        int two = 0;
        int maxC = 0;
        for (int i = 0; i < n; ++i) {
            int c = dfs(m[i], 1, i, m, used);
            if (c == 2)
                ++two;
            maxC = max(maxC, c);
        }
        two /= 2;
        for (int i = 0; i < n; ++i) {
            a[i] = 0;
            used[i] = false;
        }
        for (int i = 0; i < n; ++i) {

            if (a[i] == 0) {
                dfs1(i, m, a, used, d);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (a[i] != -1 && a[j] != -1 && m[a[i]] == a[j])
                    sum[a[i]] = max(sum[a[i]], d[i] + d[j]);
        for (int i = 0; i < n; ++i) {
            ans = ans + sum[i];
        }
        cout << max(ans / 2 + two * 2, maxC) << '\n';
    }
    return 0;
}

