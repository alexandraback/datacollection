#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("EXAMPLE.OUT", "w", stdout);

    int nTests;
    scanf("%d", &nTests);
    for (int t = 1; t <= nTests; ++t) {
        int x, y;
        scanf("%d%d", &x, &y);

        printf("Case #%d: ", t);
        if (x < 0) {
            x = -x;
            for (int i = 1; i <= x; ++i) printf("EW");
        } else {
            for (int i = 1; i <= x; ++i) printf("WE");
        }
        if (y < 0) {
            y = -y;
            for (int i = 1; i <= y; ++i) printf("NS");
        } else {
            for (int i = 1; i <= y; ++i) printf("SN");
        }

        if (t < nTests) printf("\n");
    }
}
