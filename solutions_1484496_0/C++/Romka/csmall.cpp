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

int s[510], a[510], b1[510], b2[510], n, k1, k2;
bool flag;

void rec(int i, int s1, int s2) {
    if (s1 == s2 && s1 > 0) { flag = true; throw 5; }
    if (i == n) return;

    if (s1 > s2 + s[i]) return;
    if (s2 > s1 + s[i]) return;

    rec(i + 1, s1, s2);
    b1[k1++] = a[i];
    rec(i + 1, s1 + a[i], s2);
    k1--;
    b2[k2++] = a[i];
    rec(i + 1, s1, s2 + a[i]);
    k2--;
}

void solve() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    reverse(a, a+n);
    s[n] = 0;
    for (int i = n-1; i>=0; i--) {
        s[i] = s[i+1] + a[i];
    }
    flag = false, k1 = k2 = 0;
    try {
        rec(0, 0, 0);
    } catch(...) {
        
    }

    if (flag) {
        forn(i, k1) {
            if (i) printf(" ");
            printf("%d", b1[i]);
        }
        printf("\n");
        forn(i, k2) {
            if (i) printf(" ");
            printf("%d", b2[i]);
        }
        printf("\n");
    }
    else printf("Impossible\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d:\n", q);
        solve();
    }
}
