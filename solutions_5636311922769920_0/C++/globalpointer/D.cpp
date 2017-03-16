#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

ll k, c, s;

void clear() {
}
ll ch(ll i, ll j) {
    return i*k+j;
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        printf("Case #%d: ", testnum);
        clear();
        scanf("%lld%lld%lld", &k, &c, &s);
        if ((k+c-1)/c > s) printf("IMPOSSIBLE");
        else {
            for (ll i = 0; i < k; i += c) {
                ll x = i;
                for (ll j = 1; j < c; j++) x = ch(x, std::min(i+j, k-1));
                if (i) printf(" ");
                printf("%lld", x+1);
            }
        }
        printf("\n");
    }
}

