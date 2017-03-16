#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

int rec(int cur, int prev, vector<vector<int>> &g)
{
    int ret = 1;

    for (auto &next: g[cur]) {
        if (next == prev) continue;
        ret = max(ret, rec(next, cur, g) + 1);
    }

    return ret;
}

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for (auto &a: v) {
        cin >> a;
        a--;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        g[v[i]].push_back(i);
    }

    int max_ring = 0;
    for (int i = 0; i < n; i++) {
        int cur = v[i];
        vector<bool> flg(n, false);
        int len = 1;
        flg[i] = true;
        while (cur != i && !flg[cur]) {
            flg[cur] = true;
            cur = v[cur];
            len++;
        }
        if (cur == i) {
            max_ring = max(max_ring, len);
        }
    }

    int max_seg = 0;
    vector<bool> done(n);

    for (int i = 0; i < n; i++) {
        if (done[i]) continue;

        int j = v[i];
        if (v[j] != i) continue;

        done[i] = true;
        done[j] = true;

        // cout << "** " << i << ", " << j << endl;

        max_seg += rec(i, j, g) + rec(j, i, g);
    }

    // cout << max_ring << ", " << max_seg << endl;

    cout << max(max_ring, max_seg) << endl;
}

int main()
{
    int t; cin >> t;
    for (int cn = 1; cn <= t; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}
