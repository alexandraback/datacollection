#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int T, X, R, C;
int main()
{
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        scanf("%d%d%d", &X, &R, &C);

        int sp = R * C;
        if(sp % X != 0) {
            printf("Case #%d: RICHARD\n", cas++);
            continue;
        }

        if(X > max(R, C)) {
            printf("Case #%d: RICHARD\n", cas++);
            continue;
        }

        if(X > 6) {
            printf("Case #%d: RICHARD\n", cas++);
            continue;
        }

        if(X == 1 || X == 2) {
            printf("Case #%d: GABRIEL\n", cas++);
            continue;
        }

        int a = min(R, C);
        if(X == 3) {
            if(a == 1) printf("Case #%d: RICHARD\n", cas++);
            else printf("Case #%d: GABRIEL\n", cas++);
            continue;
        }

        if(X == 4) {
            if(a < 3) printf("Case #%d: RICHARD\n", cas++);
            else printf("Case #%d: GABRIEL\n", cas++);
            continue;
        }
    }

    
    return 0;
}