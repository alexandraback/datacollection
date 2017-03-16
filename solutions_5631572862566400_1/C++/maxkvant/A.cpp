#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
int solve_stupid(vector<int> a) {
            int n = a.size();
            int ans = 0;
            vector<int> b;
            for (int i = 0; i < n; i++) {
                b.push_back(i);
            }
            do {
                for (int sz = 1; sz <= n; sz++) {
                    int ok = 1;
                    for (int i = 0; i < sz; i++) {
                        if (a[b[i]] != b[(i + 1) % sz] && a[b[i]] != b[(i - 1 + sz) % sz]) {
                            ok = 0;
                        }
                    }
                    if (ok) {
                        ans = max(ans, sz);
                    }
                }
            } while (next_permutation(b.begin(), b.end()));
    return ans;
}

int solve2(vector<int> a) {
    int res = 0;
    int n = a.size();
    int cnt = 0;
    vector<int> mx(n);
    for (int i = 0; i < n; i++) {
        vector<int> t(n);
        int v = i;
        int tim = 0;
        while (!t[v]) {
            t[v] = ++tim;
            v = a[v];
        }
        int ans = 0;
        ans = tim - t[v] + 1;
        if (v == i && ans == 2) {
            cnt++;
        }
        mx[v] = max(t[v], mx[v]);
        if (v != i && ans == 2) {
            ans++;
        }
        res = max(res, ans);
    }
    int res2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < i && a[a[i]] == i) {
            cerr << i << " " << a[i] << " " << mx[i] << " " << mx[a[i]] << endl;
            res2 += mx[i] + mx[a[i]];
        }
    }
    cerr << endl;
    return max(res2, res);
}

int main() {
    #define task "t"//"flow"
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cout << "Case #" << k << ": ";
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
            x--;
        }
        //int a1, a2;
        //cout << (a1 = solve_stupid(a)) << " " << (a2 = solve2(a)) << endl;
        //assert(a1 == a2);
        cout << solve2(a) << endl;
    }
    return 0;
}
