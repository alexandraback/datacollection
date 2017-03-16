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

const ld EPS = 1e-7;

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
        int n;
        cin >> n;
        ld a[n];
        ld b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0;
        for (int i = 0, j = 0; i < n && j < n; ++j) {
            while (i < n && a[i] - EPS < b[j]) {
                ++i;
            }
            if (i < n) {
                ++ans;
                ++i;
            }
        }
        cout << ans;

        ans = 0;
        while (n > 0) {
            --n;
            if (b[n] > a[n] + EPS) {
                int m = n;
                while (m && b[m - 1] > a[n] + EPS) --m;
                swap(b[n], b[m]);
            } else {
                ++ans;
                swap(b[n], b[0]);
            }
            sort(b, b + n);
        }
        cout << " " << ans;

        cout << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
