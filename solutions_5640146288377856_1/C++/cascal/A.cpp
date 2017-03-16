#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, v) memset((x), v, sizeof((x)))

typedef long long llong;

using namespace std;

int main() {
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int r, c, w;
        cin >> r >> c >> w;
        vector<bool> v(c, false);
        for (int i = w - 1; i < c; i += w) {
            v[i] = true;
        }
        int ls = 0;
        for (int i = 0; i < c; i++)
            if (v[i]) ls = i;
        int lft = 0, rgt = c - ls;
        for (int i = ls - 1; i >= 0; i--)
            if (v[i]) break;
            else lft++;
        cout << "Case #" << t << ": " << (r * (c / w) + (w - 1) + (lft + rgt > w))  << endl;
    }
    return 0;
}