#include <cstdio>
#include <string>
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    int p10[9];
    p10[0] = 1;
    for(int i = 1; i <= 8; i++)
        p10[i] = p10[i-1] * 10;

    for(int z = 1; z <= t; z++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int ans = 0;
        for(int n = a; n < b; n++) {
            set<int> seen;
            int ndigits = 0, n2 = n;

            while(n2)
                ndigits++, n2 /= 10;
            assert(ndigits <= 8);

            int cur = 0;
            for(int i = 0; i < ndigits; i++) {
                cur = n/p10[i] + (n%p10[i]) * p10[ndigits-i];
                if(cur > n && cur <= b && seen.find(cur) == seen.end()) {
                    seen.insert(cur);
                    ans++;
                }
            }
        }

        printf("Case #%d: %d\n", z, ans);
    }
}
