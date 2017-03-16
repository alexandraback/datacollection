#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int nCases;
    cin >> nCases;
    for (int cnum = 1; cnum <= nCases; cnum++) {
        long r, t;
        cin >> r >> t;
        long paint = t;
        long rings = 0;
        long rad = r;
        while (paint > 0) {
            paint -= 2*rad+1;
            if (paint >= 0) rings++;
            rad += 2;
        }
        printf("Case #%d: %ld\n", cnum, rings);
    }
}
