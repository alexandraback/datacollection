#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

int isInvalid(long long p, long long q) {
    if (p > q) {
        return 1;
    }
    for (int i = 0; i <= 40; ++i) {
        if (q == (1LL << i)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ", cs);
        long long p, q;
        scanf("%lld/%lld", &p, &q);
        long long g = __gcd(p, q);
        p /= g;
        q /= g;
        if (isInvalid(p, q)) {
            printf("impossible\n");
            continue;
        }
        int sol = 1;
        while (p * 2 < q) {
            sol++;
            q /= 2;
        }
        printf("%d\n", sol);
    }
    return 0;
}


