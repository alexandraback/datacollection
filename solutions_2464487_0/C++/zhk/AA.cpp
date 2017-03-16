#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned long long u64;
u64  r, t;

u64 calc_area(u64 n) {
    return n*(2ULL*r + 1ULL) + (n-1ULL)*n;
}



int main(int argc, char* argv[]) {
    int  test_cases, case_idx = 1;
    u64  lo, hi, mi;
    scanf("%d", &test_cases);
    for(; case_idx <= test_cases; ++case_idx) {
        scanf("%llu%llu", &r, &t);
        lo=1; hi=t;
        while(lo+1 < hi) {
            mi = lo + ((hi-lo)>>1);
            if(t/mi + 1 >= 2ULL*r + 2ULL*mi)
                lo = mi;
            else
                hi = mi;
        }
        printf("Case #%d: %llu\n", case_idx, lo);
    }
    return 0;
}

