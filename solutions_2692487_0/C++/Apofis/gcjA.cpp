#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <map>

using namespace std;

const int MaxN = 105;

int x[MaxN];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("sol.txt", "w", stdout);

    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; ++t) {
        int a, n;
        scanf("%d%d", &a, &n);

        int l = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
        }

        sort(x, x + n);

        for (; l < n; ++l) {
            if (a > x[l])a += x[l];
            else break;
        }

        int op = n - l, add = 0;
        while (a != 1 && l < n) {
            ++add; a += a - 1;
            for (; l < n; ++l) {
                if (a > x[l])a += x[l];
                else break;
            }

            op = min(op, n - l + add);
        }

        printf("Case #%d: %d\n", t + 1, op);
    }

    return 0;
}
