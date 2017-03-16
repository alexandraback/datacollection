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
    vector<int> v(n);
    for (auto &a: v) {
        cin >> a;
        a--;
    }
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << " ";
    // cout << endl;

    int ans = 0;

    for (int b = 0; b < (1 << n); b++) {
        vector<int> ord;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) ord.push_back(i);
        }

        if (ord.size() <= 1) continue;
        if (ord.size() <= ans) continue;

        do {
            bool ok = true;
            for (int i = 0; i < ord.size(); i++) {
                int bff = v[ord[i]];
                if (!(ord[(i + 1) % ord.size()] == bff || ord[(i + ord.size() - 1) % ord.size()] == bff)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                // if (ord.size() > ans) {
                //     for (int i = 0; i < ord.size(); i++)
                //         cout << ord[i] << " ";
                //     cout << endl;
                // }
                ans = max(ans, (int)ord.size());
                break;
            }
        } while(next_permutation(ord.begin(), ord.end()));
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
