#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long  a, m[111], n;

int main() {

    freopen("A2.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int T, cnt = 0;
    cin >> T;
    while (T > 0) {
        cout << "Case #" << (++cnt) << ": ";
        cin >> a >> n;
        for (int i = 1; i <= n; i++)
            cin >> m[i];
        sort(m + 1, m + 1 + n);
        long long res = 1000000, o = 0;
        for (int i = 1; i <= n + 1; i++) {
            res = min(res, o + n - i + 1);
            if (i == n + 1) break;
            if (a == 1) {
                res = o + n - i + 1;
                break;
            }
            while (a <= m[i]) {
                a += a - 1;
                ++o;
            }
            a += m[i];
        }
        cout << res << endl;
        --T;
    }


}
