#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b)
{
    long long c = 0;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}

void solve()
{
    long long p, q;
    char c;
    cin >> p >> c >> q;
    long long g = gcd(p, q);
    p /= g; q /= g;
    
    bool possible = false;
    for (long long i = 0; i <= 40; ++i) if ((1ll << i) == q) possible = true;
    if (p > q) possible = false;
    
    if (possible == false) {
        cout << "impossible" << endl;
        return;
    }
    
    for (long long i = 0;; ++i) {
        if ((p << i) >= q) {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
