#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL l,r,R,T,t;
int TT,sTT;
double len(LL x) {
    return (double)x + x - 1;
}
double calc(LL x) {
    return (len(R + 1) + len(R + 2*x - 1)) * (double)x * 0.5;
}
int main() {
    for (scanf("%d", &TT), sTT = TT; TT; --TT) {
        scanf("%I64d%I64d", &R, &T);
        for (l = 1, r = T / R; l < r; ) {
            t = (l + r + 1) >> 1;
            if (T - calc(t) > -1e-5) l = t;
            else r = t - 1;
        }
        printf("Case #%d: %I64d\n", sTT - TT + 1, l);
    }
    return 0;
}
