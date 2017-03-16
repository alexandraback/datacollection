#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll L[30], R[30];

int cnt(ll x) {
    int ans = 0;
    while (x) {
        ans++;
        x /= 10;
    }
    return ans;
}

ll rev(ll x) {
    ll s = 0;
    while (x) {
        s = s * 10 + x % 10;
        x /= 10;
    }
    return s;
}

void predo() {
    L[1] = 1;
    R[1] = 19;


    ll l;
    int n, m;
    for (int i = 2; i <= 16; i++) {
        m = (i + 2) / 2;
        n = i - m;
//        printf("i = %d, n = %d, m = %d\n", i, n, m);
        L[i] = rev(R[i-1]);
        R[i] = 1;
        for (int j = 0; j < n; j++) {
            R[i] *= 10;
        }
        for (int j = 0; j < m; j++) {
            R[i] *= 10;
            R[i] += 9;
        }
//        printf("[%lld, %lld]\n", L[i], R[i]);
    }
}



int main() {
    predo();
    int T;
    ll N;
    int dg = 0;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%lld", &N);
        if (N <= 10) {
            printf("Case #%d: %lld\n", kase, N);
            continue;
        }
        bool flag = 0;
        if (N % 10 == 0) {
            N--;
            flag = 1;
        }
        dg = cnt(N);
        ll ans = 1;
        ll crt = 1;
        ll p = 1;
        int tar = dg;
//        for (; R[tar+1] < N; tar++);
//        printf("tar = %d\n", tar);
        
        while (tar - p > 1) {
            ans += R[p] - crt + 1;
            crt = L[p+1];
            p++;
        }

        ll B = 1;
        for (int i = 0; i < tar-1; i++) {
            B *= 10;
        }

        ans += B - crt;
        p = B;
        crt = B;
        int n, m;

        m = (dg + 1) / 2;
        n = dg - m;
//        printf("n = %d, m = %d\n", n, m);


        ll LB = 1;
        for (int i = 0; i < n-1; i++) LB *= 10;
        
        ll C = 1;
        for (int i = 0; i < m; i++) C *= 10;
        ll LF = N / C;
        ll RT = N % C;
        // printf("%lld  %lld\n",LF, RT);
        // printf("B = %lld, ans = %lld\n", B, ans);
        if (LF == LB) {
//            puts("method 1\n");
            ans += N - crt;
        }
        else {
            ans += rev(LF) + RT;
        }
        if (flag) ans++;
        printf("Case #%d: %lld\n", kase, ans);
//        printf("B = %lld, ans = %lld\n", B, ans);
        
    }
    return 0;
}
