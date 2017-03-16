#include <stdio.h>
#define MIN(A,B) (((A) < (B)) ? (A) : (B))
#define MAX(A,B) (((A) > (B)) ? (A) : (B))

int main(void) {
    int t;
    int caso;
    int x, r, c;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        scanf(" %d %d %d", &x, &r, &c);
        printf("Case #%d: ", caso);
        if (x >= 7 || (x > 2 * MIN(r, c)) || (x > MAX(r, c)) || ((r * c) % x != 0)) {
            printf("RICHARD\n");
        } else if (MIN(r, c) <= 2 && x >= 4){
            printf("RICHARD\n");
        } else if (MIN(r, c) <= 3 && x >= 6) {
            printf("RICHARD\n");
        } else {
            printf("GABRIEL\n");
        }
    }
    return 0;
}
