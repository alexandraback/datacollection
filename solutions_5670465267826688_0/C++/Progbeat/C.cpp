#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int adj[4][4] = {
    {0, 1, 2, 3},
    {1, ~0, 3, ~2},
    {2, ~3, ~0, 1},
    {3, 2, ~1, ~0}
};

int f(int x, int y) {
    int sign = (x ^ y) >> 31;
    assert(sign == 0 || sign == ~0);
    return adj[x ^ (x >> 31)][y ^ (y >> 31)] ^ sign;
}

int main() {
    int tests, tc;
    for (cin >> tests; tc++ < tests; ) {
        int n, times;
        string w;
        cin >> n >> times >> w;
        assert(sz(w) == n);
        // if (times >= 64)
            // times = 64 + (times % 64);
        string s;
        REP (k, times)
            s += w;
        int state = 0, p = 0;
        for (char c : s) {
            int x;
            switch (c) {
                case 'i': x = 1; break;
                case 'j': x = 2; break;
                case 'k': x = 3; break;
                default: assert(false);
            }
            p = f(p, x);
            if (p == state + 1) {
                ++state;
                p = 0;
            }
        }
        printf("Case #%d: %s\n", tc, p == 0 && state == 3 ? "YES" : "NO");
    }
    return 0;
}
