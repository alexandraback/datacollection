#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int T, x, r, c;

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &x, &r, &c);
        printf("Case #%d: ", t);
        if (r * c % x != 0) {
            printf("RICHARD\n");
        } else if (x == 1 || x == 2) {
            printf("GABRIEL\n");
        } else if (x == 3) {
            if (r * c == 3)
                printf("RICHARD\n");
            else
                printf("GABRIEL\n");
        } else {
            if (r * c >= 12)
                printf("GABRIEL\n");
            else
                printf("RICHARD\n");
        }
    }

    return 0;

}
