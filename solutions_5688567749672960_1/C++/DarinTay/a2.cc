#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

#define ll long long
#define h  10000001LL


ll rev(ll x) {
    ll y = 0;
    while (x) {
        y *= 10;
        y += x%10;
        x /= 10;
    }
    return y;
}

ll len(ll x) {
    ll ans = 0;
    while (x) {
        ++ans; 
        x /= 10;
    }
    return ans;
}

ll dropDig(ll& N, bool print=true) {
    if (N <= 19) {
        ll ans = N;
        N = 1;
        return ans - 1;
    }
    ll l = len(N);
    ll M = 0;
    for (int i=0;i<l-1;++i) {
        M *= 10;
        M += 9;
    }

    ll ans = N - M;
    if (print){
    //printf("Dropping %lld to %lld in %lld\n", N, M, ans);
    }
    N = M;
    return ans;
}


ll bringTo01(ll& N) {
    ll oN;
    ll l = len(N) / 2;
    ll M = N;
    bool found = false;
    for (int i = 0;i<l;++i) {
        if (M%10 != 0) {
            found = true;
        }
        M /= 10;
    }
    if (!found) {
        int a = 0;
        while (M%10 == 0) {
            M/= 10;
            ++a;
        }
        M--;
        while (a > 0) {
            M*=10;
            M += 9;
            --a;
        }
    }


    for (int i = 0;i<l;++i) {
        M *= 10;
    }
    M += 1;

    ll ans = N - M;
    if (N == rev(M) || M == rev(M)) {
        //printf("Bringing %lld to %lld in %lld\n", N, M, ans);
    } else {
        //printf("Bringing %lld to %lld then %lld in %lld\n", N, M, rev(M), ans + 1);
        ans++;
    }
    if (dropDig(oN, false) < ans) {
        //printf("Nevermind, skipping to drop\n");
        return 0;
    }
    N = rev(M);
    return ans;
}


int main() {
    int T;
    cin>>T;

    for (int t=1;t<=T;++t) {
        ll N;
        cin>>N;

        ll ans = 1;
        while (N > 1) {
            ans += bringTo01(N);
            ans += dropDig(N);
        }

        printf("Case #%d: %lld\n", t, ans);
    }
}
