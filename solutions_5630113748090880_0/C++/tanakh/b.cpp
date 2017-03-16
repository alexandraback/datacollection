#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

int n;
vector<vector<int>> orig;

bool rec(int cur, int ix, vector<vector<int>> &bd, vector<vector<int>> &ss)
{
    // cout << cur << ", " << ix << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (bd[i][j]< 0) cout << '-';
    //         else cout << bd[i][j];
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    if (cur == n) {
        multiset<vector<int>> tt;
        for (int i = 0; i < n; i++) {
            vector<int> r, c;
            for (int j = 0; j < n; j++) {
                r.push_back(bd[i][j]);
                c.push_back(bd[j][i]);
            }
            tt.insert(r);
            tt.insert(c);
        }

        for (auto &v: orig) {
            tt.erase(tt.find(v));
        }

        assert(tt.size() == 1);

        vector<int> ans = *tt.begin();
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;

        return true;
    }

    const vector<int> *v1 = &ss[ix];
    const vector<int> *v2 = (ix + 1 < ss.size() && ss[ix+1][cur] == ss[ix][cur]) ? &ss[ix+1] : nullptr;

    vector<int> r(n), c(n);

    for (int ttt = 0; ttt < 2; ttt++) {
        swap(v1, v2);

        bool check = true;
        for (int i = 0; i < cur; i++) {
            if ((v1 && bd[cur][i] >= 0 && bd[cur][i] != (*v1)[i]) ||
                (v2 && bd[i][cur] >= 0 && bd[i][cur] != (*v2)[i])) {
                check = false;
                break;
            }
        }
        if (!check) continue;

        for (int i = 0; i < n; i++) {
            r[i] = bd[cur][i];
            c[i] = bd[i][cur];
            if (v1) bd[cur][i] = (*v1)[i];
            if (v2) bd[i][cur] = (*v2)[i];
        }

        if (rec(cur + 1, ix + (v1 ? 1 : 0) + (v2 ? 1 : 0), bd, ss)) return true;

        for (int i = 0; i < n; i++) {
            bd[cur][i] = r[i];
            bd[i][cur] = c[i];
        }
    }

    return false;
}

void solve()
{
    cin >> n;
    vector<vector<int>> ss, tt;
    for (int i = 0; i < 2 * n - 1; i++) {
        vector<int> v(n);
        for (auto &h: v) cin >> h;
        ss.push_back(v);
    }
    // sort(ss.begin(), ss.end());

    for (int i = 0; i < n; i++) {
        sort(ss.begin(), ss.end(), [&](const vector<int>& a, const vector<int> &b){
            return a[i] < b[i];
        });

        if (ss[0][i] && 1 < ss.size() && ss[0][i] == ss[1][i]) {
            tt.push_back(ss[0]);
            tt.push_back(ss[1]);
            ss.erase(ss.begin());
            ss.erase(ss.begin());
        } else {
            tt.push_back(ss[0]);
            ss.erase(ss.begin());
        }
    }

    assert(tt.size() == 2 * n - 1);
    assert(ss.empty());

    // for (int i = 0; i < 2 * n - 1; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << tt[i][j];
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    orig = tt;

    vector<vector<int>> bd(n, vector<int>(n, -1));
    assert(rec(0, 0, bd, tt));
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
