#include <bits/stdc++.h>

using namespace std;

#define SZ 1010

int p[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int d;
        scanf("%d", &d);

        int kmax = 0;
        for (int i = 0; i < d; i++) {
            scanf("%d", &p[i]);
            kmax = max(kmax, p[i]);
        }

        int ans = 2E9;

        for (int k = 1; k <= kmax; k++) {
            int tmp = 0;
            for (int i = 0; i < d; i++) {
                tmp += p[i] / k - ((p[i] % k) == 0);
            }
            tmp += k;
            ans = min(ans, tmp);
        }

        printf("Case #%d: %d\n", cs + 1, ans);
    }


    return 0;
}







