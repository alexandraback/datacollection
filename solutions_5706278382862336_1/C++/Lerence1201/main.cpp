#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const int N = 500005;

int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        long long p , q;
        scanf ("%lld/%lld" , &p , &q);
        long long g = __gcd (p , q);
        p /= g; q /= g;
        long long a = 1LL << 40;
        int ok = -1;
        for (int i = 1 ; i <= 40 ; i ++) {
            a /= 2;
            p *= 2;
            long long g = __gcd (p , q);
            p /= g; q /= g;
            if (p >= q) {
                long long A = p - q , B = q;
                long long g = __gcd (A , B);
                A /= g; B /= g;
                if (a % B == 0) {
                    ok = i;
                    break;
                }
            }
        }
        if (ok == -1) printf ("Case #%d: impossible\n" , ++ cas);
        else printf ("Case #%d: %d\n" , ++ cas , ok);
    }
    return 0;
}