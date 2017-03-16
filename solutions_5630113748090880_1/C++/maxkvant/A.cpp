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
        map<int,int> cnt;
        int n;
        cin >> n;
        for (int i = 0; i < n * (n * 2 - 1); i++) {
            int x;
            cin >> x;
            cnt[x] ^= 1;
        }
        for (auto &x : cnt) {
            if (x.se) {
                cout << x.fi << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
