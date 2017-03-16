#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdlib.h>

using namespace std;

const int MAXN = 1000100;
int x[MAXN];

inline int reverse1(int x) {
    int r = 0;
    while (x) {
        r = (10 * r) + (x % 10);
        x /= 10;
    }
    return r;
}

int f(int n) {
    memset(x, 0, sizeof(x));

    x[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (x[i]) {
            int t = i + 1;
            
            if (t <= n && !x[t]) {
                x[t] = x[i] + 1;
            }
            else {
                x[t] = min(x[i] + 1, x[t]);
            }
            t = reverse1(i);
            if (t <= n && !x[t]) {
                x[t] = x[i] + 1;
            }
            else {
                x[t] = min(x[i] + 1, x[t]);
            }
        }
    }

    return x[n];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", i + 1, f(n));
    }
    return 0;
}
