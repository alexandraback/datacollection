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

const int MAXN = 110;
int c[MAXN][MAXN];

bool check(int n, int m) {
    VI mx_r(n), mx_c(m);
    REP (i, n) {
        REP (j, m) {
            mx_r[i] = max(mx_r[i], c[i][j]);
            mx_c[j] = max(mx_c[j], c[i][j]);
        }
    }
    REP (i, n) {
        REP (j, m) {
            if (mx_r[i] != c[i][j] && mx_c[j] != c[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n, m; scanf("%d%d", &n, &m);
        REP (i, n) {
            REP (j, m) {
                scanf("%d", &c[i][j]);
            }
        }
        printf("Case #%d: %s\n", t, check(n, m) ? "YES" : "NO");
    }
    return 0;
}

