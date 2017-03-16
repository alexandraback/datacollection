#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    // #ifdef LOCAL
    // assert(freopen("inp", "r", stdin));
    // assert(freopen("out", "w", stdout));
    // #endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        cout << endl;

        int r, c, m;
        cin >> r >> c >> m;
        m = r * c - m;
        if (min(r, c) == 1 || m == 1) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << (i * c + j == 0? 'c' : (i * c + j < m? '.' : '*'));
                }
                cout << endl;
            }
            continue;
        }

        if ((min(r, c) == 2 && (m & 1)) || (m < 4) || (m < 9 && (m & 1))) {
            cout << "Impossible" << endl;
            continue;
        }

        char a[r][c];
        memset(a, '*', sizeof(a));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
            }
        }

        for (int j = 0; j < c && (m > 3 || (m && m % 2 == 0)); ++j) {
            a[0][j] = a[1][j] = '.';
            m -= 2;
        }

        for (int i = 2; i < r && m; ++i) {
            for (int j = 0; j < c && m; ++j) {
                if (j == c - 1 && m == 2) {
                    continue;
                }
                a[i][j] = '.';
                m -= 1;
            }
        }
        a[0][0] = 'c';
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << a[i][j];
            }
            cout << endl;
        }

    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
