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

void solve()
{
    int n; cin >> n;
    vector<pair<string, string>> ts(n);
    for (auto &kv: ts) cin >> kv.first >> kv.second;

    int ans = 0;

    for (int b = 0; b < (1 << n); b++) {
        set<string> fs, ss;
        for (int i = 0; i < n; i++) {
            if (!(b & (1 << i))) {
                fs.insert(ts[i].first);
                ss.insert(ts[i].second);
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) {
                if (!(fs.count(ts[i].first) && ss.count(ts[i].second))) {
                    ok = false;
                }
            }
        }

        if (ok) {
            ans = max(ans, __builtin_popcount(b));
        }
    }

    cout << ans << endl;
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
