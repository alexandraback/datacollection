#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define PER(I, N) for (int I = (N); I >= 0; --I)
#define PERR(I, A, B) for (int I = (A); I >= B; --I)
#define ITR(I, A) for (__typeof((A).begin()) I=(A).begin(), _##i=(A).end(); I!=_##i; ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
#define LB(X) __builtin_ctz((X))
#define ONES(X) __builtin_popcount((X))
typedef long long LL;
using namespace std;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
const int INF = 0x3f3f3f3f;
#define LOCALTEST 1 // change this to 1 to perform localtest on "in.txt"
#define DEBUG 0
int n;
int calc(LL x) {
    int mask = 0;
    while (x) {
        mask |= (1<<(x % 10));
        x /= 10;
    }
    return mask;
}
int main(){
    if (LOCALTEST) {
        freopen("A-small-attempt0.in", "r", stdin);
        freopen("A-small-attempt0.out", "w", stdout);
    }
    CASET {
        RI(n);
        LL ans = 0x3f3f3f3f3f3f3f3fLL;

        int mask = 0;

        LL x = n;
        REPP(i,1,1000010) {
            mask |= calc(x);
            if (mask == 1023) {
                ans = x;
                break;
            }
            x += n;
        }

        printf("Case #%d: ", case_n++);
        if (ans == 0x3f3f3f3f3f3f3f3fLL) printf("INSOMNIA\n");
        else printf("%d\n", ans);
    }
    return 0;
}
