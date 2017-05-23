#include<stdio.h>
typedef long long int lld;
#define RAN 2000000
#define N 32
#define C 500
int pn;
int p[RAN+1], rn[N+1];
int chk[RAN+1], res[N+1][C+1];
void getPrime() {
    for(int i = 2; i <= RAN; ++i) {
        if(chk[i] == 0) {
            p[pn++] = i;
            for(int j = i; j <= RAN; j += i) chk[j] = 1;
        }
    }
}
int getFactor(int n, lld j, int k) {
    for(int l = 0; l < pn; ++l) {
        if(n >= 12 && l >= 1000) break;
        if(p[l] >= j) break;
        int bn = 0;
        for(int tmp = j; tmp > 0; tmp>>=1) bn = (bn*k+(tmp&1))%p[l];
        if(bn == 0) { return p[l]; }
    }
    return 0;
}
void preprocess() {
    getPrime();
    for(int i = 1; i <= N; ++i) {
        for(lld j = ((lld)1<<(i-1)); j < ((lld)1<<i); ++j) {
            if(j&1) {
                int jam = 1;
                for(int k = 2; k <= 10; ++k) {
                    if(getFactor(i, j, k) == 0) { jam = 0; break; }
                }
                if(jam) res[i][rn[i]++] = j;
                if(rn[i] >= C) break;
            }
        }
//        printf("%d %d %d\n", i, 1<<(i-2), rn[i]);
    }
}
int main() {
    preprocess();
    int T, n, c, t = 1;
    for(scanf("%d", &T); (T--); ++t) {
        scanf("%d%d", &n, &c);
        printf("Case #%d:\n", t);
        for(int j = 0; j < c; ++j) {
            for(int tmp = res[n][j]; tmp > 0; tmp >>= 1) printf("%d", tmp&1);
            for(int k = 2; k <= 10; ++k) printf(" %d", getFactor(n, res[n][j], k));
            printf("\n");
        }
    }
    return 0;
}
