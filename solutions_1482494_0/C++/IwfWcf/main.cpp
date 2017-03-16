#include <iostream>
#include <stdio.h>
#define N 1001

using namespace std;

int a[N], b[N], f[N];

int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i], &b[i]), f[i] = 0;
            if (a[i] > b[i]) swap(a[i], b[i]);
        }
        bool find = true;
        int total = 0, sum = 0;
        while (find) {
            find = false;
            int ans1 = 0, ans2 = 0;
            for (int i = 0; i < n; i++)
                if (f[i] < 2 && sum >= b[i])
                    if (2 - f[i] > ans1) ans1 = 2 - f[i], ans2 = i;
            if (ans1 > 0) {
                sum += ans1, f[ans2] += ans1, total++, find = true;
                continue;
            }
            for (int i = 0; i < n; i++)
                if (f[i] < 1 && sum >= a[i])
                    if (ans1 == 0) ans1 = 1, ans2 = i;
                    else
                        if (b[i] > b[ans2]) ans2 = i;
            if (ans1 > 0)
                sum += ans1, f[ans2] += ans1, total++, find = true;
        }
        if (sum < n + n) printf("Case #%d: Too Bad\n", cases);
        else printf("Case #%d: %d\n", cases, total);
    }
    return 0;
}
