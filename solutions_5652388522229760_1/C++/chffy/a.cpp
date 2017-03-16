#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        static int ca = 0;
        printf("Case #%d: ", ++ca);
        if (n == 0) {
            puts("INSOMNIA");
            continue;
        }
        LL m = 0;
        int mask = 0;
        while (__builtin_popcount(mask) != 10) {
            m += n;
            for (LL x = m; x > 0; x /= 10) {
                mask |= (1 << (x % 10));
            }
        }
        cout << m << endl;
    }
}
