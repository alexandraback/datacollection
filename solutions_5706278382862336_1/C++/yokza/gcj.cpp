#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define N 310
typedef unsigned long long ULL;

ULL gcd(ULL a, ULL b) {
    return (!b) ? a: gcd(b, a % b);
}

void solve() {
    char d;
    ULL p, q, n;
    cin >> p >> d >> q;
    ULL gc = gcd(p, q);
    p /= gc;
    q /= gc;
    int g = 0;
    n = q;
    while(!(n & 1)) {
        n>>=1;
    }
    if(n!=1) {cout << "impossible\n"; return;}
    while (true) {
        g++;
        if(q & 1) {
            if( q==p ) {cout << g-1 << endl; return;}
            break;
        }
        else {
            q >>= 1;
            if(p > q || (p == q && q == 1)) {
                // if check (p-q / q);
                // check
                cout << g << endl;
                return;
            }
        }
    }
    cout << "impossible" << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}