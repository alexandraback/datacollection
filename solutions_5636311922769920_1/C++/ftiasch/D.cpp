#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        printf("Case #%d:", t);
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        if (k <= c * s) {
            std::vector<long long> power(c);
            power[0] = 1;
            for (int i = 1; i < c; ++ i) {
                power[i] = power[i - 1] * k;
            }
            std::vector<long long> result(s);
            int count = 0;
            for (int j = 0; j < c; ++ j) {
                for (int i = 0; i < s; ++ i) {
                    result[i] += (count % k) * power[j];
                    count ++;
                }
            }
            std::sort(result.begin(), result.end());
            assert(static_cast<int>(std::unique(result.begin(), result.end()) - result.begin()) == s);
            for (int i = 0; i < s; ++ i) {
                printf(" %lld", 1 + result[i]);
            }
            puts("");
        } else {
            puts(" IMPOSSIBLE");
        }
    }
    return 0;
}
