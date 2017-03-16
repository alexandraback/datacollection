#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

lol ans;
lol a[100];

void update(lol x, lol tt) {
    while(x) {
        if(a[x % 10] != tt)
            ans--;
        a[x % 10] = tt;
        x /= 10;
    }
}

int main() {
    inp("input.txt");
    out("output.txt");
    lol t, tt;
    scanf("%lld", &t);
    for(tt = 1; tt <= t; tt++) {
        lol n, i;
        scanf("%lld", &n);
//n = tt;
        ans = 10;
        printf("Case #%lld: ", tt);
        for(i = 1; i <= 1e+6; i++) {
            update(i * n, tt);
            if(ans == 0) {
                printf("%lld\n", i * n);
                break;
            }
        }
        if(i > 1e+6)
            printf("INSOMNIA\n");

    }
}
