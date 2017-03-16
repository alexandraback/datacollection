#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0? a: gcd(b, a%b);
}

int main() {
    int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        long long a, b;
        long long gcdt;
        
        scanf("%lld/%lld", &a, &b);
        gcdt = gcd(a, b);
        a = a/gcdt;
        b = b/gcdt;
        
        long long pow = 1;
        int i = 0, j = 0;
        for (i = 0; pow < b; i++, pow *= 2);
        
        if (b != pow) {
            printf("impossible\n");
            continue;
        }
        
        long long pow2 = pow;
        for (j = 0; pow2 > a; j++, pow2 /= 2);
        
        printf("%d\n", j);
            
    }
}