#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        int n;
        scanf("%d", &n);
        double a[n+1], b[n+1];
        int cnt1 = 0, cnt2 = 0;
        bool hash[n+1];
        memset(hash, true, sizeof(hash));
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf", &b[i]);
        }
        sort(a, a+n);
        sort(b, b+n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (a[j] > b[i] && hash[j]) {
                    cnt1 ++;
                    hash[j] = false;
                    break;
                }
            }
        }
        memset(hash, true, sizeof(hash));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (b[j] > a[i] && hash[j]) {
                    cnt2 ++;
                    hash[j] = false;
                    break;
                }
            }
        }
        printf("Case #%d: ", z);
        printf("%d %d\n", cnt1, n-cnt2);
    }
    return 0;
}
