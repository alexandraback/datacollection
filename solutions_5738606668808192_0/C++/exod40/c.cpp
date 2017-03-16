#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n = 16;

inline long long conv(long long x, long long base) {
    long long s = 0;
    long long f = 1;
    for (int i = 0; i < n; i++) {
        s += !!(x & (1 << i)) * f;
        f *= base;
    }
    return s;
}

int isprime(long long x, long long &div) {
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            div = i;
            return 0;
        }
    }
    return 1;
}

int main() {
    int fnd = 0;

    printf ("Case #1:\n");
    for (long long i = (1LL << (n - 1)) + 1; i < (1LL << n); i+=2) {
        int ok = 1;
        vector<long long> p;
        for (int j = 2; j <= 10; j++) {
            long long x = conv(i, j);
            long long div;

            if (isprime(x, div)) {
                ok = 0;
                break;
            }
            p.push_back(div); 
        
        }
        if (ok) {
            for (int j = n - 1; j >= 0; j--) {
                printf ("%d", !!(i & (1 << j)));
            }
            for (int j = 0; j < (int)p.size(); j++) {
                printf (" %lld", p[j]);
            }
            printf ("\n");
            if ((++fnd) == 50) break;
        }
    }
    return 0;
}
