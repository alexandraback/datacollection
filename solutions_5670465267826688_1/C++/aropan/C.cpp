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

int SIGN[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

int F[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

bool Solve()
{
    ll last[2][4];

    int upd[2][4];
    int cnt = 1;
    memset(upd, 0, sizeof(upd));
    memset(last, 0, sizeof(last));

    int n;
    ll m;
    string s;
    cin >> n >> m;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'i' + 1;
    }

    int sig = 0;
    int val = 0;
    int state = 0;
    for (ll i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            sig ^= SIGN[val][a[j]];
            val = F[val][a[j]];
            if (
                (state == 0 && sig == 0 && val == 1) ||
                (state == 1 && sig == 0 && val == 3)
            ) {
                state += 1;
                cnt += 1;
            }
        }

        if (state == 2) {
            if (last[sig][val]) {
                ll p = i - last[sig][val];
                i += (m - i) / p * p;
            }
        } else {
            if (upd[sig][val]) {
                return false;
            }
            upd[sig][val] = cnt;
        }

        last[sig][val] = i;
    }
    return state == 2 && sig == 1 && val == 0;
}

int main(int /* argc */, char** /* argv */)
{
    assert(freopen("inp", "r", stdin));
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        cout << (Solve()? "YES" : "NO") << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
