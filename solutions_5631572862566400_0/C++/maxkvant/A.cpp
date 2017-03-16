#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

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
        cout << ans << endl;
    }
    return 0;
}
