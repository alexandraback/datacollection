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

const char* answers[] = {"RICHARD", "GABRIEL"};

bool can(int n, int m, int w, int k) {
    assert(n + w == k + 1);
    assert(n <= w);
    assert(w <= m);
    assert(w <= n + 1);
    for (int d = (n - 1) * (w - 1); d >= 0; --d) {
        bool ok = false;
        for (int x = 0; x + w <= m; ++x) {
            if ((d + x * n) % k == 0) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}

int main() {
    int tests, tc = 0;
    for (cin >> tests; tc++ < tests; ) {
        int k, n, m;
        cin >> k >> n >> m;
        if (n > m)
            swap(n, m);
        bool res = (n * m) % k == 0;
        bool ok = false;
        for (int x = 1; x <= k; ++x) {
            int y = k - x + 1;
            if (x <= n && y <= m || x <= m && y <= n)
                continue;
            res = false;
        }
        for (int x = 1; res && x <= k; ++x) {
            int y = k - x + 1;
            if (min(x, y) == n) {
                if (x == n)
                    res &= can(n, m, y, k);
                if (y == n)
                    res &= can(n, m, x, k);
            }
        }
        printf("Case #%d: %s\n", tc, answers[res]);
    }
    return 0;
}
