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

struct group { int d, k, m; };

long solve(int d, long m, int dlim, long mlim) {
    if (m == mlim)
        return d < dlim;
    if (m < mlim) {
        long cnt = (long)((d + (360 - dlim) * mlim / m) / 360);
        if (cnt > 0)
            --cnt;
        return cnt;
    }
    if (d < dlim)
        return 1;
    return mlim * (360 - dlim) < m * (360 - d);
}

long solve(group g, long dlim, long mlim) {
    long res = 0;
    REP (i, g.k)
        res += solve(g.d, g.m + i, dlim, mlim);
    return res;
}

long solve(vector<group> &groups, int dlim, int mlim) {
    long res = 0;
    for (auto g : groups)
        res += solve(g, dlim, mlim);
    //cout << "! " << dlim << ' ' << mlim << ' ' << res << endl;
    return res;
}

long solve(vector<group> &groups) {
    long res = 0;
    for (auto &g : groups)
        res += g.k;
    for (auto g0 : groups) {
        REP (i0, g0.k) {
            res = min(res, solve(groups, g0.d, g0.m + i0));
        }
    }
    return res;
}

int main() {
    int tests, tc = 0;
    for (cin >> tests; tc < tests; ) {
        printf("Case #%d: ", ++tc);
        int n;
        vector<group> groups;
        for (cin >> n; n --> 0; ) {
            group g;
            cin >> g.d >> g.k >> g.m;
            groups.pb(g);
        }
        cout << solve(groups) << endl;
    }
    return 0;
}
