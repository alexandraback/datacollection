#include <stdio.h>
#include <set>
using namespace std;
typedef long long ll;

set<ll> s;
#define B 100000000

int i, j, k,n ,m, x, y, z, tt, T, p;
ll t;
int a, b;
int main() {
    freopen("small.in", "r", stdin);    freopen("small.out", "w", stdout);
    scanf("%d", &T);
    for (tt = 1; tt <= T; tt ++) {
        scanf("%d%d", &a, &b);
        p = 1;
        x = a;
        while (x >= 10) {
            x /= 10;
            p *= 10;
        }
        s.clear();
        for (i= a; i <= b; i ++) {
            x = i;
            for (j = 0; j < 7; j ++) {
                y = x % 10;
                x = x / 10 + y*p;
                if (x > i && x >= a && x <= b) {
                    s.insert((ll)i * B + x);
                }
            }
        }
        printf("Case #%d: %d\n", tt, (int)s.size());
    }
}



