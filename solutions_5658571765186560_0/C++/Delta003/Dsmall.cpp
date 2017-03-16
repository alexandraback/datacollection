#include <cstdio>
#include <algorithm>

using namespace std;

// in small 1 <= x, r, c <= 4
int x, r, c, cases;

int main() {
    freopen("D-small-attempt3.in", "r", stdin);
    freopen("D-small-attempt3.out", "w", stdout);

    scanf("%d", &cases);
    int counter = 0;
    while (cases--) {
        counter++;

        scanf("%d %d %d", &x, &r, &c);

        if (r > c) swap(r, c);

        if (x == 1) {
            printf("Case #%d: GABRIEL\n", counter);
        } else if (x == 2) {
            if (r % 2 == 0 || c % 2 == 0) printf("Case #%d: GABRIEL\n", counter);
            else printf("Case #%d: RICHARD\n", counter);
        } else if (x == 3) {
            switch (r) {
            case 1:
                printf("Case #%d: RICHARD\n", counter);
                break;
            case 2:
                if (c == 3) printf("Case #%d: GABRIEL\n", counter);
                else printf("Case #%d: RICHARD\n", counter);
                break;
            case 3:
                printf("Case #%d: GABRIEL\n", counter);
                break;
            case 4:
                printf("Case #%d: RICHARD\n", counter);
                break;
            }
        } else /* x == 4 */ {
            switch (r) {
            case 1:
                printf("Case #%d: RICHARD\n", counter);
                break;
            case 2:
                printf("Case #%d: RICHARD\n", counter);
                break;
            case 3:
                if (c == 4) printf("Case #%d: GABRIEL\n", counter);
                else printf("Case #%d: RICHARD\n", counter);
                break;
            case 4:
                printf("Case #%d: GABRIEL\n", counter);
                break;
            }
        }
    }

    return 0;
}

