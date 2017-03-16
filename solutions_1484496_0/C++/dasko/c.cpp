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

int us[3000010];
int c[110];

int main(void) {
    int T; scanf("%d", &T);
    FOR (t, 1, T + 1) {
        int n; scanf("%d", &n);
        REP (i, n)
            scanf("%d", &c[i]);
        memset(us, 0, sizeof us);
        int rA = -1, rB = -1;
        FOR (i, 1, (1 << n)) {
            int sum = 0;
            REP (j, n) {
                if (i & (1 << j))
                    sum += c[j];
            }
            if (us[sum]) {
                rA = us[sum];
                rB = i;
                break;
            }
            us[sum] = i;
        }
        printf("Case #%d:\n", t);
        if (rA == -1)
            puts("Impossible");
        else {
            int s1 = 0, s2 = 0;
            REP (i, n) {
                if (rA & (1 << i)) {
                    printf("%d ", c[i]);
                    s1 += c[i];
                }
            }
            puts("");
            REP (i, n) {
                if (rB & (1 << i)) {
                    printf("%d ", c[i]);
                    s2 += c[i];
                }
            }
            assert(s1 == s2 && rA != rB);
            puts("");
        }
    }
    return 0;
}

        
