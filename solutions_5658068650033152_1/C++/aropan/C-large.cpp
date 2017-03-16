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
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n, m, k;
        cin >> n >> m >> k;
        if (m > n) {
            swap(n, m);
        }
        int f[n + 1][m + 1];
        int ans = k;
        if (k > 1)
            for (int x = 1; x <= m; ++x) {
                memset(f, 0, sizeof(f));
                f[0][x] = x;
                for (int i = 0; i < n; ++i)
                    for (int j = 1; j <= m; ++j)
                        if (f[i][j]) {
                            if (f[i][j] >= k) {
                                ans = min(ans, i * 2 + x + j - 2);
                            }
                            for (int d = -2; d <= 2; ++d) {
                                int y = j + d;
                                if (1 <= y && y <= m) {
                                    f[i + 1][y] = max(f[i + 1][y], f[i][j] + y);
                                }
                            }
                        }
            }
        cout << ans << endl;
        cerr << "Case #" << t << ": " << ans << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
