#include <iostream>
#include <cstdio>

using namespace std;


typedef long long LL;

LL gcd(LL a, LL b) {
    LL r;
    while(b > 0) {
         r = a % b; a = b; b = r;
    }
    return a;
}

bool check(LL x) {
    while((x & 1) == 0) x >>= 1;
    return (x == 1);
}

int main()
{
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int ci, cn;

    scanf("%d", &cn);
    for(ci = 1; ci <= cn; ci++) {
        LL p, q, ans = 0;
        scanf("%I64d/%I64d", &p, &q);
        LL g = gcd(p, q);
        p /= g; q /= g;

        if(!check(q)) { ans = -1; }
        else {
            while(p < q) {
                ans++;
                q >>= 1;
            }
        }
        cout << "Case #"<< ci <<": ";
        if(ans == -1) cout << "impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}
