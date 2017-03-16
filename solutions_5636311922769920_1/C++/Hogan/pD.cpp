#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int times = 0; times < T; times++) {
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);

        vector<long long> vct(c, 0);
        vct[0] = 1;
        for (int i = 1; i < c; i++) {
            vct[i] = vct[i-1] * k;
        }

        printf("Case #%d:", times+1);
        if (ceil(1.0 * k / c) > s) {
            printf(" IMPOSSIBLE\n");
            continue;
        } 

        vector<long long> ret;
        for (int i = 0; i < k; i += c) {
            long long t = 0;
            for (int j = 0; j < min(c, k-i); j++) {
                t += vct[c-1-j] * (i+j);
            }
            ret.emplace_back(t);
        }

        for (auto& v : ret) {
            printf(" %lld", v+1);
        }
        puts("");
    }
}
