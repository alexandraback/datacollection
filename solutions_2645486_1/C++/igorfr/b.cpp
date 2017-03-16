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

#define MAXN 10008

int n;
ll maxe, r, v[MAXN], p[MAXN];

int main () {
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso) {
        scanf ("%lld %lld %d", &maxe, &r, &n);

        for (int i = 0; i < n; ++i) {
            scanf ("%lld", &v[i]);
            p[i] = 200000000;

            for (int j = 0; j < i; ++j) {
                if (v[i] > v[j] && p[j] > i) p[j] = i;
            }
        }

        ll ans = 0, e = maxe;
        for (int i = 0; i < n; ++i) {
            if (e == maxe) {
                //printf ("%lld entrou no caso em que e == maxe\n", v[i]);
                ll use = min(e, (p[i] - i) * r);
                ans += v[i] * use;
                e -= use;
                //printf ("novo ans = %lld\n", ans);
            } else if (e + (p[i] - i) * r > maxe) {
                //printf ("%lld entrou no caso em que é ruim esperar\n", v[i]);
                ll use = min(e, e + (p[i] - i) * r - maxe);
                ans += v[i] * use;
                e -= use;
                //printf ("novo ans = %lld\n", ans);
            }
            e = min(maxe, e + r);
        }

        printf ("Case #%d: %lld\n", caso, ans);
    }

    return 0;
}

