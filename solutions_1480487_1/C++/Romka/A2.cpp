#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, a[210];

void solve() {
    scanf("%d", &n);
    int S = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        S += a[i];
    }

    for (int i = 0; i < n; i++) {
        double l = 0, r = 1, m;
        while (r-l > 5e-9) {
            m = (l + r) * 0.5;
            double sc = a[i] + m * S;
            double rest = 1 - m;
            forn(j, n)
                if (j != i)
                    if (a[j] < sc) rest -= (sc - a[j]) / S;
            if (rest > 0) l = m;
            else r = m;
        }
        printf(" %.7f", l * 100);
    }
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d:", q);
        solve();
    }
}
