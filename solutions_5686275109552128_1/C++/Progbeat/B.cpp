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

int main() {
    int tests, tc = 0;
    for (cin >> tests; tc++ < tests; ) {
        int n;
        cin >> n;
        vector<int> a(n);
        int res = 0;
        for (int &x : a) {
            cin >> x;
            res = max(res, x);
        }
        for (int h = 1; h <= res; ++h) {
            int cur = 0;
            for (int x : a) {
                cur += (x - 1) / h;
            }
            res = min(res, cur + h);
        }
        printf("Case #%d: %d\n", tc, res);
    }
    return 0;
}
