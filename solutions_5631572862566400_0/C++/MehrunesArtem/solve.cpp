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

int t, n, mx, c;
bool u[1024][1024];
vector< int > v;

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
        mx = 0; v.clear();
        memset(u, 0, 1024 * 1024);
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> c;
            c--;
            u[j][c] = 1;
            v.push_back(j);
        }
        do {
            for (int l = 1; l <= n; ++l) {
                bool b = true;
                for (int j = 0; j < l; ++j) {
                    if (!(u[v[(j + 1) % l]][v[j]] ^ u[v[(j + 1) % l]][v[(j + 2) % l]])) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    mx = max(mx, l);
                }
            }
        } while (next_permutation(v.begin(), v.end()));
        cout << "Case #" << i + 1 << ": " << mx << '\n';
    }
    return 0;
}