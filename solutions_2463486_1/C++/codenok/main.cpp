#include "codejam-dsl.hpp"

bool pali(lng x) {
    if (x < 10) return true;
    int n = (int) ceil(log10( (long double) (x + 1) ));
    lng high = 1, y = x;
    F_(n-1) high *= 10;
    F_(n/2) {
        if ((x/high)%10 != y % 10) return false;
        high /= 10;
        y /= 10;
    }
    return true;
}

bool hackable(lng x) {
    if (x < 10) return true;
    if (x % 10 != 2 && x % 10 != 1) return false;
    int n = (int) ceil(log10( (double) (x + 1) ));
    lng high = 1;
    F_(n-1) high *= 10;
    return (x/high) == 2 || (x/high) == 1;
}

void run()
{
    lng A = rdl(), B = rdl(), ans = 0;
    int ra = (int) ceil(sqrt(A)), rb = (int) floor(sqrt(B));
    for (lng i = ra; i <= rb; ++i) {
        if (hackable(i) && pali(i) && pali(i*i)) ++ans;
    }
    cout << ans;
}
