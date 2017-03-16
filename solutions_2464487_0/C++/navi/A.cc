#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

const double PI = acos(-1.0);
const ll INF = 0x7FFFFFFFFFFFFFFFLL;

int main() {
    int T;
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        ll r, t;
        scanf("%lld%lld", &r, &t);
        ll pl = 1, pr = t;
        while (pl + 1 < pr) {
            ll pm = pl + (pr - pl) / 2;
            ll cur = 2 * pm + 2 * r - 1;
            if (INF / pm >= cur) {
                cur = cur * pm;
            } else {
                cur = INF;
            }
            //printf("pm = %lld, cur = %lld\n", pm, cur);
            (cur <= t ? pl : pr) = pm;
        }
        printf("Case #%d: %lld\n", caseNum, pl);
    }
    return 0;
}
