#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int qq = 1; qq <= t; ++qq) {
        int c, d, v;
        scanf("%d %d %d", &c, &d, &v);
        vector<bool> a(v+1, false);
        a[0] = true;
        for (int i = 0; i < d; ++i) {
            int t;
            scanf("%d", &t);
            for (int j = v - t; j>=0; --j)
                if (a[j]) a[j+t] = true;
        }
        int cnt = 0;
        for (int i = 0; i <= v; ++i)
            if (!a[i]) {
                ++cnt;
                for (int j = v - i; j>=0; --j)
                    if (a[j]) a[j+i] = true;
            }
        printf("Case #%d: %d\n", qq, cnt);
    }
    return 0;
}
