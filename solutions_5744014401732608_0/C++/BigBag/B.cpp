#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;

int t, n, a[max_n][max_n];
long long x;

bool get_bit(long long x, int poz) {
    return (bool) (x & (1LL << poz));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("B-small.out", "w", stdout);
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cin >> n >> x;
        long long mx = (1LL << (n - 2));
        cout << "Case #" << test << ": ";
        if (x > mx) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            memset(a, 0, sizeof(a));
            for (int i = n - 1; i > 1; --i) {
                for (int j = i + 1; j <= n; ++j) {
                    a[i][j] = 1;
                }
            }
            if (x == mx) {
                a[1][n] = 1;
                --x;
            }
            for (int i = n - 1; i > 1; --i) {
                if (get_bit(x, n - 1 - i)) {
                    a[1][i] = 1;
                }
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    cout << a[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
