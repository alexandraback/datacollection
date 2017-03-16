#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

void Solve()
{
    int n;
    cin >> n;
    const int MAXA = 1000;
    int f[MAXA + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            f[j] += ((x - j) + j - 1) / j;
        }
    }
    int ans = MAXA;
    for (int i = 1; i <= MAXA; ++i) {
        ans = min(ans, f[i] + i);
    }
    cout << ans << "\n";
}

int main(int /* argc */, char** /* argv */)
{
    assert(freopen("inp", "r", stdin));
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        Solve();
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
