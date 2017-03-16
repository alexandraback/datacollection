#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;

typedef long long LL;
LL a,b,c,mid, ll, rr;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test, tt;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        scanf("%I64d%I64d", &a, &b);
        c = a * 2 + 1;
        ll = 1; rr = b / c + 3;
        while (ll + 1 < rr) {
            mid = (ll + rr) / 2;
            if ((c + c + (mid - 1) * 4) / 2 > b / mid ) rr = mid; else ll = mid;
        }
        printf("Case #%d: %I64d\n",tt, ll);
    }
    return 0;
}
