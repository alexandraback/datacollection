#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 10010

ll divi[11][MAXN];

int main() {
    int t;
    int n, J;
    cin >> t >> n >> J;
    ll base = 1;
    base |= (ll)1 << (n - 1);
    for (int j = 0; j < MAXN; j+=2) {
        ll p = base + j;
        for (int i = 3; i <= 1000; i+=2) {
            for (int k = 2; k <= 10; k++) {
                if (divi[k][p - base]) continue;
                ll x = 1;
                ll remaind = 0;
                for (int w = 0; w < n; w++) {
                    if (p & ((ll)1 << w)) {
                        remaind += x % i;
                    }
                    remaind %= i;
                    x %= i;
                    x *= k;
                }
                if (!remaind) {
                    divi[k][p - base] = i;
                }
            }
        }
    }
    cout << "Case #1:" << endl;
    for (int i = 0; i < MAXN; i++) {
        bool cond = true;
        for (int j = 2; j <= 10; j++) {
            if (!divi[j][i]) cond = false;
        }
        if (cond) {
            J--;
            for (int j = n-1; j >= 0; j--) {
                if (((ll)i + base) & ((ll)1 << j)) cout << "1";
                else cout << "0";
            }
            for (int j = 2; j <= 10; j++) {
                cout << " " << divi[j][i];
            }
            cout << endl;
        }
        if (!J) break;
    }


    return 0;
}
