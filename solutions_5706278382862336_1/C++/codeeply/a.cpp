#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define type_assign(a, b) \
    typeof(b) a = b
#define iterate(a, b) \
    for (type_assign(a, b.begin()); a != b.end(); ++a)
#define clr(a, c) \
    memset(a, c, sizeof(a))
#define foreach(i, a, b) \
    for (i = a; i < b; ++i)

int64_t p, q;

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int i, j, k, t, nc = 0;

    scanf("%d", &t);
    while (t--) {
        scanf("%lu/%lu", &p, &q);

        int64_t d = gcd(p, q);
        p /= d;
        q /= d;

        for (i = 0; ((int64_t)1 << i) < q; ++i);
        for (j = 0; ((int64_t)1 << j) <= p; ++j);

        if (((int64_t)1 << i) != q) {
            printf("Case #%d: impossible\n", ++nc);
        } else {
            printf("Case #%d: %d\n", ++nc, i - j + 1);
        }
    }
    return 0;
}
