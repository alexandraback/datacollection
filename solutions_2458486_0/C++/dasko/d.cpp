#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

const int MAXN = 21;
VI keys[MAXN], start; int open[MAXN];
int dp[1 << 20], cnt[50];

VI solve(int n) {
    VI us;
    FC (start, it) {
        us.PB(*it);
    }
    REP (i, n) {
        FC (keys[i], it) {
            us.PB(*it);
        }
    }
    sort(ALL(us)); us.erase(unique(ALL(us)), us.end());
    FC (start, it) {
        *it = find(ALL(us), *it) - us.begin();
    }
    REP (i, n) {
        VI::iterator f = find(ALL(us), open[i]);
        if (f == us.end()) {
            return VI();
        }
        open[i] = f - us.begin();
        FC (keys[i], it) {
            *it = find(ALL(us), *it) - us.begin();
        }
    }
    int K = SZ(us);
    dp[0] = -1;
    FOR (mask, 1, (1 << n)) {
        memset(cnt, 0, sizeof(int) * K);
        FC (start, it) {
            ++cnt[*it];
        }
        REP (i, n) {
            if (mask & (1 << i)) {
                continue;
            }
            --cnt[open[i]];
            FC (keys[i], it) {
                ++cnt[*it];
            }
        }
        dp[mask] = -2;
        REP (i, n) {
            if (!(mask & (1 << i))) {
                continue;
            }
            if (cnt[open[i]] > 0 && dp[mask - (1 << i)] != -2) {
                dp[mask] = i;
                break;
            }
        }
    }
    if (dp[(1 << n) - 1] == -2) {
        return VI();
    }
    VI res;
    for (int mask = (1 << n) - 1; mask != 0; ) {
        int k = dp[mask];
        res.PB(k + 1);
        mask -= (1 << k);
    }
    return res;
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int K, n; scanf("%d%d", &K, &n);
        start.clear();
        REP (i, K) {
            int a; scanf("%d", &a);
            start.PB(a);
        }
        REP (i, n) {
            scanf("%d", &open[i]);
            int k; scanf("%d", &k);
            keys[i].clear();
            REP (j, k) {
                int a; scanf("%d", &a);
                keys[i].PB(a);
            }
        }
        VI res = solve(n);
        if (res.empty()) {
            printf("Case #%d: IMPOSSIBLE\n", t);
        } else {
            printf("Case #%d:", t);
            FC (res, it) {
                printf(" %d", *it);
            }
            puts("");
        }
    }
    return 0;
}
