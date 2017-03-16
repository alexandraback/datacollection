#include <bits/stdc++.h>

#define lld long long int
#define DBG(x)

using namespace std;

lld p10[16];

int intsize(lld N) {
    for(int i = 0; i < 16; ++i) {
        if(p10[i] > N) return i;
    }
}

lld inv(lld N) {
    lld M = 0;
    while(N) {
        M *= 10;
        M += N % 10;
        N /= 10;
    }
    return M;
}

int mceil2(lld k) {
    if((k/2)*2 != k) {
        return k/2+1;
    } else {
        return k/2;
    }
}

lld findsol(lld N) {
    lld msk, ans = 2;
    int sz;
    if(N == 1) --ans;
    while(N > 1) {
        DBG(printf("P1\n");)
        sz = intsize(N);
        if(sz == 1) {
            DBG(printf("Tirou %lld\n", N-2);)
            ans += N - 2;
            break;
        }
        DBG(printf("P2 %lld\n", N);)
        msk = N % p10[mceil2(sz)];
        if(msk > 1) {
            DBG(printf("Tirou %lld\n", msk-1);)
            ans += msk - 1;
            N -= msk - 1;
        } else if(msk == 0) {
            DBG(printf("Tirou 1\n");)
            N -= 1;
            ans += 1;
            continue;
        }
        DBG(printf("P3 %lld\n", N);)
        N = inv(N);
        msk = N % p10[sz/2];
        if(msk > 1) {
            DBG(printf("Inverteu (%lld)\n", N);)
            DBG(printf("Tirou %lld\n", msk+1);)
            ans += msk + 2;
            N -= msk + 1;
        } else {
            if(msk == 1) {
                DBG(printf("Tirou 2\n");)
                N = inv(N) - 2;
                ans += 2;
            } else {
                DBG(printf("Tirou 1\n");)
                N = inv(N) - 1;
                ans += 1;
            }
        }
        DBG(printf("P4 %lld\n", N);)
    }
    return ans;
}

int main() {
    int T, t;
    lld N;
    p10[0] = 1;
    for(int i = 1; i < 16; ++i) p10[i] = p10[i-1] * 10;
    scanf("%d", &T);
    for(t = 0; t < T; ++t) {
        scanf("%lld", &N);
        printf("Case #%d: %lld\n", t+1, findsol(N));
    }
}
