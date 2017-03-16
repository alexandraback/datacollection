#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s1[5] = "EW", s2[5] = "NS";

void gao(int n, char *s) {
    int st = n > 0;
    for (int i = abs(n); i > 0; --i) {
        putchar(s[st]);
        putchar(s[st ^ 1]);
    }
}

void solve() {
    int x, y;
    scanf("%d %d", &x, &y);
    gao(x, s1);
    gao(y, s2);
    puts("");
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++cas);
        solve();
    }
    return 0;
}
