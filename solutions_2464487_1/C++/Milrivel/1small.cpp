#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const double pi = atan2(0, -1);

int main(void) {
    freopen("A-large.in", "r", stdin);
    freopen("dataout.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        long long r, t;
        scanf("%I64d%I64d", &r, &t);
        long long lbd = 1, ubd = 1e18;
        long long mid;
        while (ubd - lbd > 1) {
            mid = (lbd + ubd) >> 1;
            if (2 * (double)mid * (double)mid +
                (double)mid * (2 * (double)r - 1)
                <= (double)t) {
                lbd = mid;
            } else {
                ubd = mid;
            }
        }
        printf("Case #%d: %I64d\n", cases, lbd);
    }
    return 0;
}
