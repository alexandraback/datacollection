#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

Int gcd(Int a, Int b) { return b == 0 ? a : gcd(b, a%b); }

int f(Int a, Int b) {
    int c = 0;
    Int d = b;
    while (d%2==0) c++, d/=2;
    if (d != 1) return -1;
    if (c > 40) return -1;
    while (a > 1) c--, a/=2;
    return c;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        Int a, b;
        scanf(" %lld/%lld", &a, &b);
        int ans = f(a/gcd(a, b), b/gcd(a, b));
        printf("Case #%d: ", _q+1);
        if (ans == -1) printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}
