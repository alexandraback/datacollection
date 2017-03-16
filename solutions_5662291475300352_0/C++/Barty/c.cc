#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
int a[2], b[2];
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
    int T;
    scanf ("%d" , &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n;
        scanf ("%d" , &n);
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            int d , h , m;
            scanf ("%d%d%d" , &d , &h , &m);
            for (int j = 0; j < h; ++j) {
                a[tot] = d;
                b[tot++] = m + j;
            }
        }
        int ans = 0;
        if (tot > 1) {
            if (a[0] > a[1] || (a[0] == a[1] && b[0] < b[1])) {
                swap(a[0], a[1]);
                swap(b[0], b[1]);
            }
            LL A = b[0] * (360LL - a[0]);
            LL C = b[1] * (360LL - a[1] + 360);
            if (C <= A) {
                ans = 1;
            }
            A = b[0] * (360LL - a[0] + 360);
            C = b[1] * (360LL - a[1]);
            if (A <= C)
                ans = 1;
        } 
        printf ("Case #%d: %d\n", ca, ans);

    }
    return 0;
}