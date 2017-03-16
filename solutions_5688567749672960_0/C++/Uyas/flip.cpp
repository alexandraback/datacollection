#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXX = 1010101;
int f[MAXX + 13];

int rev( int x ) {
    int ret = 0;
    while (x > 0) {
        ret = ret * 10 + (x % 10);
        x /= 10;
    }
    return ret;
}

int main() {
    for (int i = 0; i < MAXX; ++i) f[i] = MAXX + 123;
    f[0] = 0; f[1] = 1;
    for (int i = 1; i < MAXX; ++i) {
        if (f[i] + 1 < f[i + 1]) f[i + 1] = f[i] + 1;
        int r = rev(i);
        if (r < MAXX)
        if (f[i] + 1 < f[r]) f[r] = f[i] + 1;
    }
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        int n; scanf("%d", &n);
        printf("Case #%d: %d\n", cas, f[n]);
    }
    return 0;
}

        
        
