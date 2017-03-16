#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

const int MAX_N = 100 + 20;

int T;
int N, M;
int A[MAX_N][MAX_N];

int tp[MAX_N][MAX_N];

int main() {
    scanf("%d", &T);
    REP(t, T) {
        scanf("%d %d", &N, &M);
        REP(r, N) REP(c, M) scanf("%d", &A[r][c]);

        memset(tp, 0, sizeof(tp));

        REP(r, N) {
            int maxa = 0;
            REP(c, M) maxa = max(maxa, A[r][c]);

            REP(c, M)
                if (A[r][c] != maxa)
                    tp[r][c] |= 1;
        }

        REP(c, M) {
            int maxa = 0;
            REP(r, N) maxa = max(maxa, A[r][c]);

            REP(r, N)
                if (A[r][c] != maxa)
                    tp[r][c] |= 2;
        }

        bool any = false;
        REP(r, N) REP(c, M)
            if (tp[r][c] == 3) {
                any = true;
                break;
            }

        printf("Case #%d: ", t + 1);
        if (any) puts("NO");
        else puts("YES");
    }
}
