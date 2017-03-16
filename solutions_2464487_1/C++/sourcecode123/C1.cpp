#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <cmath>

#define CHECK(N, R) ((2*N*N) + (N*((2*R)-1)))

using namespace std;

int main() {
    int T;
    uint64_t ans, check;
    long double D, x, temp, r, b, t, a, c;
    
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%Le%Le", &r, &t);
        b = 2*r-1;
        c = -1*t;
        D = (b*b)-(8*c);
        temp = ceil((sqrt(D) - b)/4);

        ans = ((uint64_t)(temp));
        check = ((uint64_t)(t));
        //cout << r << "  " << t << "  " << ans << endl;
        while (CHECK(ans, r) > check)
            ans--;

        printf("Case #%d: %llu\n", i, ans);    
    }
    return 0;
}
