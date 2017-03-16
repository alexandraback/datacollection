//Author: Artem Romanov
#include <bits/stdc++.h>
//#define TASK "file"

#define F   first
#define S   second
#define y0  y84678
#define y1  y53021

using namespace std;
typedef long double dbl;

const dbl PI = 3.141592653589793238462643383279502884L;
const dbl E = 2.718281828459045235360287471352662498L;
const dbl EPS = 1e-12L;

int t, n, c;
int a[2560];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(11); cout.setf(ios::fixed);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#elif defined(TASK)
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        memset(a, 0, 2560 * sizeof(int));
        for (int k = 0; k < 2 * n - 1; ++k) {
            for (int j = 0; j < n; ++j) {
                cin >> c;
                a[c]++;
            }
        }
        cout << "Case #" << i + 1 << ": ";
        for (int j = 0; j < 2560; ++j) {
            if (a[j] & 1) {
                cout << j << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}