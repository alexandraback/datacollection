#include <bits/stdc++.h>

using namespace std;

map<string,int> id;

int x[1005], y[1005];

void Solve() {
    id.clear();
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        if (!id.count(a)) id[a] = cnt++;
        if (!id.count(b)) id[b] = cnt++;
        x[i] = id[a];
        y[i] = id[b];
    }
    int fs[105], sd[105], pl[105], sz, used[105];
    int result = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < cnt; ++j) fs[j] = sd[j] = 0;
        sz = 0;
        for (int j = 0; j < n; ++j) {
            used[j] = 0;
            if (~i & (1 << j)) fs[x[j]] = 1, sd[y[j]] = 1;
            else pl[sz++] = j;
        }
        bool ok = true;
        for (int j = 0; j < sz; ++j) {
            int cur = pl[j];
            if (!fs[x[cur]] || !sd[y[cur]]) {
                ok = false;
                break;
            }
        }
       // cout << sz << " " << i << " " << ok << " " << pl[0] << " " << x[2] << " " << y[2] << endl;
        if (ok) result = max(result, sz);
    }
    cout << result << '\n';
}

int main() {
    int z;
    cin >> z;
    for (int i = 1; i <= z; ++i) {
        cout << "Case #" << i << ": ";
        Solve();
    }
    return 0;
}
