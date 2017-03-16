#include <iostream>
#include <cstdio>
#include <stdint.h>

using namespace std;
int main() {
    int T;
    uint64_t count, curRad, curDisk, t, r;
    int64_t paintLeft;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%llu%llu", &r, &t);
        count = 0;
        paintLeft = t;
        curRad = r;
        while (1) {
            curDisk = (2*curRad)+1;
            paintLeft -= curDisk;
            curRad += 2;
            if (paintLeft >= 0)
                count++;
            else
                break;
            //cout << paintLeft << endl;;
        }
        printf("Case #%d: %llu\n", i, count);
    }
    return 0;
}
