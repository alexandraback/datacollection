#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}


int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        char b;
        long long p, q;
        cin >> p >> b >> q;

        long long g = gcd(p, q);
        p /= g;
        q /= g;

        if((q & (q-1)) != 0 || p > q) {
            puts("impossible");
        } else {
            int aq = 0, ap = 0;
            for(int i = 0; i < 40; i++)
                if(q & (1LL << i)) {
                    aq = max(i+1, aq);
                }

            for(int i = 0; i < 40; i++)
                if(p & (1LL << i)) {
                    ap = max(i+1, ap);
                }

            printf("%d\n", aq-ap);
        }
    }

    return 0;
}

