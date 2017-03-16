#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long R, TT;

// 2n*n + (2r-1) * n <= TT
long long solve() {
    long long r = (long long)sqrt(TT / 2) + 1;
    long long l = 0;

    while (l < r - 1) {
        long long m = (l + r) / 2;
        long long fm = 2*m*m + (2*R-1)*m;
        if (fm == TT)
            return m;
        if (fm < 0 || fm > TT)
            r = m;
        else
            l = m;
    }

    return l;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        scanf("%lld%lld", &R, &TT);
        
        printf("Case #%d: %lld\n", testcase, solve());
    }
    return 0;
}
