#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main () {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int r, c, w;
        cin >> r >> c >> w;

        int k = 0;
        if (c % w == 0)  k = 1;

        printf("Case #%d: %d\n", tt, r * (c / w) + w - k);

    }

    return 0;
}
