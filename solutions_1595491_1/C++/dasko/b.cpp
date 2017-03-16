#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

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

int mx(int g, int s) {
    for (int i = 10; i >= 0; --i) {
        if (!s) {
            if (3 * i == g || (i > 0 && 3 * i - 1 == g) || (i > 0 && 3 * i - 2 == g))
                return i;
        }
        else {
            if (i > 1 && (3 * i - 2 == g || 3 * i - 3 == g || 3 * i - 4 == g))
                return i;
        }
    }
    return -1;
}

int c[110], dp[110][110], us[110][110], P;
const int INF = 1000;

int rec(int a, int k) {
    if (a == -1) {
        if (k == 0)
            return 0;
        return -INF;
    }
    if (us[a][k])
        return dp[a][k];
    us[a][k] = 1;
    int res = -INF;
    if (mx(c[a], 0) != -1)
        res = max(res, rec(a - 1, k) + (mx(c[a], 0) >= P ? 1 : 0));
    if (k > 0 && mx(c[a], 1) != -1)
        res = max(res, rec(a - 1, k - 1) + (mx(c[a], 1) >= P ? 1 : 0));
    return dp[a][k] = res;
}

int main(void) {
    int T; scanf("%d", &T);
    FOR (t, 1, T + 1) {
        int n, s; scanf("%d%d%d", &n, &s, &P);
        REP (i, n)
            scanf("%d", &c[i]);
        memset(us, 0, sizeof us);
        printf("Case #%d: %d\n", t, rec(n - 1, s));
    }
    return 0;
}
