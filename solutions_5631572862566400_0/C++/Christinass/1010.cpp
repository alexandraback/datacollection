#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include "iostream"
using namespace std;
#define N 100010

int k;
long long M, prime[15];
long long ans;
long long fct[15][N];

void init() {
    for (int i = 0; i < k; i += 1) {
        fct[i][0] = 1;
        for (int j = 1; j < prime[i]; j += 1)
            fct[i][j] = fct[i][j - 1] * j % prime[i];
    }
}
long long mul(long long a, long long b, long long mod) {
    long long ans = 0;
    while (b != 0){
        if (b % 2 == 1){
            ans = (ans + a) % mod;
        }
        a = (a + a) % mod;
        b /= 2;
    }
    return ans;
}
long long mypow(long long t, long long p, long long mod) {
    t = t % mod;
    long long res = 1;
    while (p) {
        if (p & 1) res = mul(res, t, mod);
        t = mul(t, t, mod);
        p >>= 1;
    }
    return res;
}
long long C(long long n, long long m, long long mod, long long *p) {
    if (n < m) return 0;
    long long ret = p[n] * mypow(p[m], mod - 2, mod) % mod;
    return ret * mypow(p[n - m], mod - 2, mod) % mod;
}
long long lucas(long long n, long long m, int mod, long long *p) {
    long long res = 1;
    while (n && m && res) {
        res = res * C(n % mod, m % mod, mod, p) % mod;
        n /= mod;
        m /= mod;
    }
    return res;
}
int main() {
    long long n, m;
    int ncas;
    scanf("%d", &ncas);
    while (ncas--) {
        scanf("%lld%lld%d", &n, &m, &k);
        M = 1;
        for (int i = 0; i < k; i += 1) {
            scanf("%lld", &prime[i]);
            M *= prime[i];
        }
        init();
        long long ans = 0;
        for (int i = 0; i < k; i += 1) {
            long long mi = M / prime[i];
            long long ti = lucas(n, m, prime[i], fct[i]);
            long long pi = mypow(mi, prime[i] - 2, prime[i]);
            long long tmp = ti * pi % M;
            tmp = mul(tmp, mi, M);
            ans = (ans + tmp) % M;
        }
        printf("%lld\n", ans);
    }
    return 0;
}