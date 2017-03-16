#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char buf[100];

long long a[1000], tot;

bool judge(long long x) {
    sprintf(buf, "%lld", x);
    int i = 0, j = strlen(buf) - 1;
    while(i < j)
        if (buf[i++] != buf[j--])
            return false;
    return true;
}
int main() {
    freopen("t.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    tot = 0;
    a[tot++] = -1;
    for(long long i = 1, j; i * i < 100000000000000LL; i++) {
        j = i * i;
        if (judge(i) && judge(j)) {
            a[tot++] = j;
        }
    }
    int t;
    long long x, y;
    int tx, ty;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld%lld", &x, &y);
        tx = lower_bound(a, a + tot, x) - a;
        ty = lower_bound(a, a + tot, y + 1) - a;
        printf("Case #%d: %d\n", i, ty - tx);
    }
    return 0;
}
