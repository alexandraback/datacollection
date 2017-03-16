#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

double memo[1600][1600];
int limit, need, have;

double doit(int left, int right) {
    int sofar = left + right;

    if(left >= need) return 1;
    if(sofar == have) return 0;

    double& ret = memo[left][right];
    if(ret == ret) return ret;

    if(left < limit && right < limit)
        ret = doit(left+1, right)/2 + doit(left, right+1)/2;
    else {
        assert(left < limit);
        ret = doit(left+1, right);
    }

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);

        int acc = 0;
        limit = 0;

        while(acc + 2*limit + 1 < n) {
            acc += 2*limit + 1;
            limit += 2;
        }
        assert(limit < 1600);

        int level2 = max(abs(x-y), abs(x+y));
        double ans;

        if(level2 < limit) ans = 1;
        else if(level2 > limit) ans = 0;
        else if(x == 0) ans = (acc + 2*limit + 1 == n);
        else {
            memset(memo, -1, sizeof memo);

            need = abs(y)+1;
            have = n - acc;
            assert(need <= limit);

            ans = doit(0, 0);
        }

        printf("Case #%d: %.7lf\n", z, ans);
    }
}
