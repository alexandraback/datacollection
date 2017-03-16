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
        int c = n * m;
        int a[n + 2][m + 2];
        int ans = k;
        for (int i = 0; i < (1 << c); ++i) {
            memset(a, 0, sizeof(a));
            int res = 0;
            for (int j = 0; j < c; ++j)
                if (i & (1 << j)) {
                    a[j / m + 1][j % m + 1] = 1;
                    res += 1;
                }
            if (res >= ans) {
                continue;
            }
            queue < pair < int, int > > q;
            a[0][0] = 1;
            q.push(make_pair(0, 0));
            int r = 2 * (n + m) + 4 + n * m - k;
            while (q.size() && r >= 0) {
                --r;
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int dx = -1; dx <= 1; dx += 1)
                    for (int dy = -1 + (int)(dx != 0); dy <= 1; dy += 2) {
                        x += dx;
                        y += dy;
                        if (0 <= x && x <= n + 1 && 0 <= y && y <= m + 1 && a[x][y] == 0) {
                            a[x][y] = 1;
                            q.push(make_pair(x, y));
                        }
                        x -= dx;
                        y -= dy;
                    }
            }
            if (r >= 0) {
                ans = res;
            }
        }
        cout << ans;
        cout << endl;
        cerr << "Case #" << t << ": " << ans << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
