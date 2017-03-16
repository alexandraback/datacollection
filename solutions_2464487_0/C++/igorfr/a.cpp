#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

typedef long long ll;

ll r, t;

inline ll f(ll n) {
    return 2*n*r + 2*n*(n-1) + n;
}

int main () {
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso) {
        scanf ("%lld %lld", &r, &t);

        ll lo = 0, hi = min(t / (2*r), (ll) ceil(sqrt(t))) + 2;

        while (hi - lo > 1) {
            ll mid = lo + (hi - lo) / 2;

            ll tmp = f(mid);
            if (0 <= tmp && tmp <= t) lo = mid;
            else hi = mid;
        }

        printf ("Case #%d: %lld\n", caso, lo);
    }

    return 0;
}


