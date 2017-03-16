#include <cstdio>
#include <algorithm>

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        long long c, d, v;
        scanf("%lld %lld %lld", &c, &d, &v);

        long long ary[d];
        for (int i = 0; i < d; i++)
            scanf("%lld", &ary[i]);
        std::sort(ary, ary + d);

        int ans = 0;
        long long unav = 1;
        for (int i = 0; i < d; i++) {
            while (unav < ary[i]) {
                ans++;
                unav *= c + 1;
            }
            unav += c * ary[i];
        }

        while (unav <= v) {
            ans++;
            unav *= c + 1;
        }

        printf("Case #%d: %d\n", t, ans);


    }

}
