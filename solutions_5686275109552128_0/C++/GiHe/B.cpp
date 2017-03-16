#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int a[1011], n;

bool valid(int spectime, int totaltime) {
    int remtime = totaltime - spectime;
    for (int i = 1;i <= n; i++) {
        if (a[i] <= remtime) continue;
        if (a[i] % remtime == 0) {
            spectime -= a[i] / remtime - 1;
        } else {
            spectime -= a[i] / remtime;
        }
        if (spectime < 0) return false;
    }
    return true;
}

bool check(int totaltime) {
    for (int i = 0; i < totaltime; i++) {
        if (valid(i, totaltime)) return true;
    }
    return false;
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int testcase;
    scanf("%d", &testcase);
    int testnum = 0;

    while (testcase) {
        testcase--;testnum++;
        scanf("%d", &n);
        int maxp = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d", &a[i]);
            maxp = max(maxp, a[i]);
        }
        int l = 1, r = maxp, ans = maxp;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (check(mid)) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        printf("Case #%d: %d\n", testnum, ans);
    }
}
