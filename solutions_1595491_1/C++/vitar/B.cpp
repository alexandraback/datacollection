#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define N 105

int a[N];

int i, j, k,n, m, x, y, z, t, T, tt, p, res;

int main() {
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    scanf("%d", &T);
    for (tt = 1; tt <= T; tt ++) {
        scanf("%d%d%d", &n, &m, &p);
        for (i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        res = 0;
        if (p == 0) {
            x = 0;
        } else {
            x = p + 2*(p-1);
        }
        if (p <= 2) {
            y = p;
        } else {
            y = p + 2*(p-2);
        }
        for (i = 0; i < n; i ++ ) {
            if (a[i] >= x) {
                res ++;
            } else if (a[i] >= y && m > 0) {
                res ++;
                m --;
            }
        }
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}







