#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
void init() {
    
}

bool ispal(int x) {
    char s[10];
    sprintf(s, "%d", x);
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
int main() {
    init();
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        LL l, r;
        scanf("%I64d %I64d", &l, &r);
        printf("Case #%d: ", T);
        printf("%I64d\n", brute(l, r));
    }
}
