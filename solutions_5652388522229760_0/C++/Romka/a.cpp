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


void update(int n, set<int>& seen) {
    for (; n > 0; n /= 10) seen.insert(n % 10);
}

int doit(int n) {
    set<int> seen;
    update(n, seen);
    int x = n;

    while (seen.size() < 10) {
        x += n;
        update(x, seen);
    }

    return x;
}

void solve() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("INSOMNIA\n");
        return;
    }

    printf("%d\n", doit(n));
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d: ", q);
        solve();
    }
    return 0;
}
