#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPF(i, a, b) for (int i = (a); i <= (b); ++i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u>>1;
const int maxn = 100000 + 10;

int a, b;
double p[maxn], c[maxn], f[maxn];

int main() {
    freopen("a.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++ca);
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; ++i) {
            scanf("%lf", &p[i]);
            if (i) c[i] = c[i - 1] * p[i];
            else c[i] = p[i];
        }
        f[0] = b + 1;
        for (int i = 1; i <= a; ++i) {
            f[i] = c[i - 1] * (b - i + 1) + (1 - c[i - 1]) * (b * 2 - i + 2);
            f[i] = min(f[i], (double)b + 2);
            f[i] = min(f[i], f[i - 1] + 1);
        }
        printf("%.12lf\n", f[a]);
    }
    return 0;
}

