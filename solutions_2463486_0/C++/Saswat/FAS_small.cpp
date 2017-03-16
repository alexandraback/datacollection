#include <stdio.h>

int main() {
    unsigned a, b, tests;
    scanf("%u", &tests);

    for(int t = 0; t < tests; ++t) {
        scanf("%u %u", &a, &b);

        int ans;
        if(b < 4)           ans = 1;
        else if(b < 9)      ans = 2;
        else if(b < 121)    ans = 3;
        else if(b < 484)    ans = 4;
        else                ans = 5;

        if(a > 484)         ans = 0;
        else if(a > 121)    ans -= 4;
        else if(a > 9)      ans -= 3;
        else if(a > 4)      ans -= 2;
        else if(a > 1)      ans -= 1;

        printf("Case #%d: %d\n", t+1, ans);
    }

    return 0;
}
