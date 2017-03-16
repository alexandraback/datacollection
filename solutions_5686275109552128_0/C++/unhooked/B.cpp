#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T, n, a[2222];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int res = 99999999;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= 1000; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += (a[j] - 1) / i;
            }
            res = min(res, i + tmp);
        }
        printf("Case #%d: %d\n", t, res);
    }

    return 0;

}
