#include <cstdio>
#include <iostream>

using namespace std;

int T, n;
long long a, b;

long long lowbit(long long x) {
    return x & -x;
}

long long gcd(long long a, long long b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("a.txt", "w", stdout);
    
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> a;
        getchar();
        cin >> b;
        
        long long t = gcd(a, b);
        a /= t;
        b /= t;
        
        if (b != lowbit(b)) {
            printf("Case #%d: impossible\n", cs);
            continue;
        }
        while (a > 1) {
            a >>= 1;
            b >>= 1;
        }
        int ans = 0;
        for (; b; ++ans, b >>= 1);
        printf("Case #%d: %d\n", cs, ans - 1);
    }
    return 0;
}
