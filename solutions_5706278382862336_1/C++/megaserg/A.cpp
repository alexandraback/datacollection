#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long int64;
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define PROBLEM "A"

inline int64 gcd(int64 a, int64 b) {
    if (a > b) return gcd(b, a);
    if (a == 0) return b;
    return gcd(b % a, a);
}

inline bool istwo(int64 x) {
    while (x % 2 == 0) x /= 2;
    return x == 1;
}

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        
        int64 p = 0, q = 0;
        scanf("%lld/%lld", &p, &q);
        cerr << p << " " << q << endl;
        
        int64 g = gcd(p, q);
        p = p / g;
        q = q / g;
        
        if (p == 0 || !istwo(q)) {
            printf("impossible");
        } else {
            int gen = 0;
            while (p < q) {
                gen++;
                q /= 2;
            }
            if (gen > 40) {
                printf("impossible");
                cerr << "!!!!!" << endl;
            } else {
                printf("%d", gen);
            }
        }

        printf("\n");
    }

    return 0;
}
