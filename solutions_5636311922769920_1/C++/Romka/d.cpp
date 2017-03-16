#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

void solve() {
    ll k, c, s;
    cin >> k >> c >> s;
    int d = 1;
    if (c == 1) d = 0;
    if (s < k - d) {
        printf(" IMPOSSIBLE");
    } else {
        forn(q, max(1LL, k - d))
            printf(" %lld", k - q);
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
    return 0;
}
