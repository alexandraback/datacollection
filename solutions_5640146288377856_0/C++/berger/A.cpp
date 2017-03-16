#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int r, c, w;

int main() {
    int TT, T;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        scanf("%d%d%d", &r, &c, &w);
        int ans = 0;
        ans += r * c/w;
        if (c % w == 0)
            ans += w-1;
        else
            ans += w;
        printf("%d\n", ans);
        
    }
}
        