#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
 
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    while (a > 0 && b > 0)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

bool in_gen(ll a, ll b, int k)
{
    ll pw40 = (1LL << 40);
    if (pw40 % b != 0) return false;
    ll g = pw40 / b;
    a *= g;
    ll pwkm = (1LL << (40 - k));
    return a >= pwkm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        
        ll p, q;
        cin >> p;
        cin.ignore();
        cin >> q;
        
        ll g = gcd(p, q);
        p /= g;
        q /= g;
        
        bool good = false;    
        for (int k = 1; k <= 40; ++k)
            if (in_gen(p, q, k)) {
                cout << k << endl;
                good = true;
                break;
            }
        if (!good) {
            cout << "impossible" << endl;
        }
    }
 
    return 0;
}
