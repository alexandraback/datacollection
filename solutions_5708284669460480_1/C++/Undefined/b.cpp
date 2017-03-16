#include <bits/stdc++.h>

using namespace std;

int z[101], K, L, S, dict[30];
char k[101], l[101];

int calcz() {
    int Le = 0, Ri = 0;
    for (int i = 1; i < L; i++) {
        if (i > Ri) {
            Le = Ri = i;
            while (Ri < L && l[Ri-Le] == l[Ri]) Ri++;
            z[i] = Ri-Le; Ri--;
        } else {
            int k = i-Le;
            if (z[k] < Ri-i+1) z[i] = z[k];
            else {
                Le = i;
                while (Ri < L && l[Ri-Le] == l[Ri]) Ri++;
                z[i] = Ri-Le; Ri--;
            }
        }
    }
}

int main() {
    long long int hi, lo;
    int T, t, p, maxb;
    double ans, prob;
    bool possible;
    scanf("%d", &T);
    for(t = 0; t < T; ++t) {
        ans = 0;
        scanf("%d %d %d", &K, &L, &S);
        scanf(" %s", k);
        scanf(" %s", l);
        memset(dict, 0, sizeof(dict));
        for(int i = 0; i < K; ++i) ++dict[k[i]-'A'];
        possible = true;
        for(int i = 0; i < L; ++i) {
            if(dict[l[i]-'A'] == 0) {
                possible = false;
            }
        }
        if(possible) {
            memset(z, 0, sizeof(z));
            calcz();
            p = 0;
            for(int i = 1; i < L; ++i) {
                if(z[i] == L-i) {
                    p = i;
                    break;
                }
            }
            if(p) {
                maxb = (S - L) / p + 1;
            } else {
                maxb = S/L;
            }
            prob = 1;
            hi = lo = 1LL;
            for(int i = 0; i < L; ++i) {
                // prob *= dict[l[i]-'A'] / (double) K;
                hi *= dict[l[i]-'A'];
                lo *= K;
                if(hi > 10000000000000LL || lo > 10000000000000LL) {
                    prob *= hi / (double) lo;
                    hi = lo = 1;
                }
            }
            prob *= hi / (double) lo;
            ans = maxb - prob * ((S+1)-L);
        }
        printf("Case #%d: %lf\n", t+1, ans);
    }
}
