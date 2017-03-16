#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

set<int> s;

void add_dig(ll x) {
    while (x) {
        s.insert(x%10);
        x /= 10;
    }
}

int main() {
    int t; scanf("%d", &t);
    FO(z,0,t) {
        ll n; scanf("%lld", &n);
        printf("Case #%d: ", z+1);
        if (n == 0) printf("INSOMNIA\n");
        else {
            s.clear();
            add_dig(n);
            ll m = n;
            while (sz(s) < 10) {
                m += n;
                add_dig(m);
            }
            printf("%lld\n", m);
        }
    }
}

