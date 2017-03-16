#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int32_t N = 101;

int32_t A[N];
int32_t a, n;

int32_t Solve(int32_t sz, int32_t idx) {
    if (idx == n) {
        return 0;
    }
    if (sz > A[idx]) {
        return Solve(sz + A[idx], idx + 1);
    }
    if (sz == 1) {
        return n - idx;
    } else {
        return min(n - idx, 1 + Solve(sz + sz - 1, idx));
    }
}
int32_t main() {
    int32_t cas = 0;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic++) {
        scanf("%d%d", &a, &n);
        for (int32_t i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A, A + n);
        int32_t ans = Solve(a, 0);
        printf("Case #%d: %d\n", ic, ans);
    }
    return 0;
}
