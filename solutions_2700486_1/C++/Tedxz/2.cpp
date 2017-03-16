#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T, x, y, n, l, in, k;
long double ans, s;
long double f[50000];

long double C(int n, int m) {
    return f[m] / f[n] / f[m - n];
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("b.out", "w", stdout);
    
    cin >> T;
    f[0] = 1;
    for (int i = 1; i <= 50000; ++i) {
        f[i] = i * f[i - 1];
    }
    for (int t = 1; t <= T; ++t) {
        cin >> n >> x >> y;
        if (x < 0) x = -x;
        l = (x + y) / 2;
        in = (1 + (1 + (l - 1) * 4)) * l / 2;
        k = y + 1;
        n -= in;
        //cout << "last " << n << endl;
        
        if (n >= l * 4 + 1) {
            cout << "Case #" << t << ": 1.0" << endl;
            continue;
        }
        if (n == l * 4 && x != 0) {
            cout << "Case #" << t << ": 1.0" << endl;
            continue;
        }
        if (n >= l * 2 + k) {
            cout << "Case #" << t << ": 1.0" << endl;
            continue;
        }
        
        if (n < k) {
            cout << "Case #" << t << ": 0.0" << endl;
            continue;
        }
        s = 0;
        if (x != 0) {
            for (int i = k; i <= n; ++i) {
                //cout << i << " " << n << " " << s << endl;
                s += C(i, n);
            }
        } else {
            s = 0; 
        }
        ans = s / exp(log(2) * n);
        
        cout << "Case #" << t << ": " << ans << endl;
        
    }
    return 0;
}
