
#include <iostream>
#include <inttypes.h>
using namespace std;

uint64_t calc(uint64_t r, uint64_t n)
{
    return 2*n*n - n + 2*r*n;
}

int main(int argc, char *argv[])
{
    int problems;
    cin >> problems;

    for (int n=1; n<=problems; ++n) {
        int64_t r, t;
        int64_t y;
        cin >> r >> t;
        
        for (y=1; t>=calc(r, y); y<<=1) {
            // do nothing
        }

        // cerr << "y=" << y << ", calc=" << calc(r, y) << "\n";

        int64_t lb = y >> 1;
        int64_t ub = y;
        int64_t step = (ub - lb)/2;
        y = lb + step;

        while (step > 0) {
            if (calc(r, y) <= t) {
                y += step;
            }
            else {
                y -= step;
            }
            
            step >>= 1;
        }

        if (calc(r, y) > t) {
            y--;
        }

        cout << "Case #" << n << ": " << y << "\n";
    }
    return 0;
}
