#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOREACH(i,c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#include <cstdio>
using namespace std;

int calcbit(int a, int ma, int b, int mb, int k, int mk)
{
    int r = 0;
    REP(ta, 2) REP(tb, 2) REP(tk, 2) {
        if (ma && ta != a) continue;
        if (mb && tb != b) continue;
        if (mk && tk != k) continue;
        if ((ta & tb) == tk) r++;
    }
    //printf("  %d %d %d %d %d %d", a, ma, b, mb, k, mk);
    //printf(" -> %d\n", r);
    return r;
}

int solve_case(int A, int B, int K)
{
    int result = 0;
    int uA = A; //uA = uA * 2 + 1;
    int uB = B; //uB = uB * 2 + 1;
    int uK = K; //uK = uK * 2 + 1;
    int mA = -1, pA = 1;
    for (; pA <= A; mA <<= 1, pA <<= 1) {
        if ((pA & uA) == 0) continue;
        int mB = -1, pB = 1;
        for (; pB <= B; mB <<= 1, pB <<= 1) {
            if ((pB & uB) == 0) continue;
            int mK = -1, pK = 1;
            for (; pK <= K; mK <<= 1, pK <<= 1) {
                if ((pK & uK) == 0) continue;
                int tA = (uA & mA & ~pA);
                int tB = (uB & mB & ~pB);
                int tK = (uK & mK & ~pK);
                int diff = 1;
                //printf("%d %d %d\n", pA, pB, pK);
                for (int i = 0; i < 31; i++) {
                    diff *= calcbit((tA >> i) & 1, (mA >> i) & 1,
                                    (tB >> i) & 1, (mB >> i) & 1,
                                    (tK >> i) & 1, (mK >> i) & 1);
                }
                result += diff;
            }
        }
    }
    return result;
}

int main() 
{
    int T;
    scanf("%d", &T);

    REP(_c, T) {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);
        printf("Case #%d: %d\n", _c + 1, solve_case(A, B, K));
    }
}
