#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int k, c, s;
        scanf("%d %d %d", &k, &c, &s);
        if (s * c < k) {
            printf("Case #%d: IMPOSSIBLE\n", t);
            continue;
        }
        vector<long long> ans;
        long long num = 0;
        for (int d = 0; d < k; ++d) {
            if (d % c == 0) {
                if (d > 0) {
                    ans.push_back(num);
                }
                num = 0;
            }
            num = num * k + d;
        }
        ans.push_back(num);
        printf("Case #%d:", t);
        for (int i = 0; i < (int) ans.size(); ++i) {
            printf(" %lld", ans[i] + 1);
        }
        printf("\n");
    }
    return 0;
}
