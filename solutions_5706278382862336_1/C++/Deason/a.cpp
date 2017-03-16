#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long, long long);
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, cases=0;
    char k;
    long long p, q, g;
    cin >> T;
    while (T--)
    {
        cout << "Case #" << (++cases) << ": ";
        cin >> p >> k >> q;
        g = gcd(p, q);
        p/=g;
        q/=g;
        if (__builtin_popcountll(q) != 1)
        {
            cout << "impossible" << endl;
        }
        else
        {
            int ANS = 1;
            while(q > 1 && q/2 > p)
            {
                ++ANS;
                q>>=1;
            }
            cout << ANS << endl;
        }
    }
    return 0;
}
long long gcd(long long a, long long b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
