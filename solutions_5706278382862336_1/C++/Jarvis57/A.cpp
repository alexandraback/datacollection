#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
using namespace std;

int main() {
    ios :: sync_with_stdio(false);
    int ntest; scanf("%d", &ntest);

    FOR(test,1,ntest) {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        long long g = __gcd(a, b);

        a /= g; b /= g;

        long long cnt = 0;
        while (b % 2 == 0) {
            ++cnt;
            b /= 2;
        }
        cout << "Case #" << test << ": ";
        if (b != 1) cout << "impossible" << endl;
        else {
            b <<= cnt;
            while (b % (1LL<<50) != 0) {
                a *= 2LL;
                b *= 2LL;
            }
            int res = -1;
            FOR(i,1,40) {
                if (a >= (1LL<<(50LL-i))) {
                    res = i;
                    break;
                }
            }
            if (res < 0) cout << "impossible" << endl;
            else cout << res << endl;
        }
    }
    return 0;
}
