#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

struct tt
{
    int x, y;
    bool operator < (const tt &o) const
    {
        if (x != o.x) {
            return x < o.x;
        }
        return y < o.y;
    }
}e;

map<tt, bool> my; 



int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int c = 0, o = 0, a = 0, b = 0, x = 0, y = 0, i = 0, j = 0, k = 0, g = 0, lx[32] = { 0 }, ans = 0;
    scanf("%d", &c);
    for (o = 1; o <= c; o ++) {
        my.clear();
        scanf("%d%d", &a, &b);
        ans = 0;
        for (i = a; i <= b; i ++) {
            x = i;
            g = 0;
            while (x) {
                lx[g ++] = x % 10;
                x /= 10;
            }
            for (j = g - 2; j >= 0; j --) {
                y = 0;
                for (k = 0; k < g; k ++) {
                    y = y * 10 + lx[(j-k+g)%g];
                }
                if (y > i && y >= a && y <= b) {
                    e.x = i;
                    e.y = y;
                    if (my[e]) {
                    }
                    else {
                        my[e] = true;
                        ans ++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", o, ans);
    }
    return 0;
}
              
