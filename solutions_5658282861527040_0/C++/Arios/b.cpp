#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int solve() {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    int cnt = 0;
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            cnt += (i & j) < k;
    return cnt;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: %d\n", ++cas, solve());
    }
    return 0;
}
