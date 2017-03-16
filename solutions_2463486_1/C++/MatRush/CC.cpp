#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

bool ispal(LL x) {
    char s[10];
    sprintf(s, "%I64d", x);
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

bool issqr(int x) {
    int s = sqrt(double(x));
    if (s * s == x && ispal(s)) return true;
    if ((s - 1) * (s - 1) == x && ispal(s - 1)) return true;
    if ((s + 1) * (s + 1) == x && ispal(s + 1)) return true;
    return false;
}

LL brute(int l, int r) {
    LL ans = 0;
    for (int i = l; i <= r; i++) {
        if (issqr(i) && ispal(i)) {
            ans++;
        }
    }
    return ans;
}
LL all[10000000];
int idx;
void init() {
    for (int i = 1; i <= 10000000; i++) {
        if (ispal(i) && ispal((LL)i * i)) {
            all[idx++] = (LL)i * i;
        }
    }
    all[idx++] = 0x7FFFFFFFFFFFFFFFLL;
}

int main() {
    init();
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        LL l, r;
        scanf("%I64d %I64d", &l, &r);
        printf("Case #%d: ", T);
        //printf("%I64d\n", brute(l, r));
        //l-1,l,r;
        int L = lower_bound(all, all + idx, l) - all;
        int R = upper_bound(all, all + idx, r) - all;
        printf("%d\n", R - L);
    }
}
