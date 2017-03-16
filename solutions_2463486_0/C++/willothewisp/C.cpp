#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

const ll LIM = int(1e7);

int tmp[20];
bool ispal(ll n) {
    int e = 0;
    while (n) { tmp[e++] = n % 10; n /= 10; }
    REP(i, e) if (tmp[i] != tmp[e - 1 - i]) return false;
    return true;
}

ll sp[LIM];
int nsp = 0;
void precomp(ll lim) {
    for (ll x = 1; x <= lim; ++x) {
        if (!ispal(x) || !ispal(x*x)) continue;
        sp[nsp++] = x*x;
    }
}

int main() {
    precomp(LIM);

    int T;
    scanf("%d", &T);

    REP(t, T) {
        ll A, B;
        scanf("%lld %lld", &A, &B); ++B;
        printf("Case #%d: %d\n", t + 1, int(lower_bound(sp, sp + nsp, B) - lower_bound(sp, sp + nsp, A)));
    }
}
