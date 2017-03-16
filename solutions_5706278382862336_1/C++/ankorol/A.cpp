#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
    while ((a != 0) && (b != 0))
    {
        if (a > b)
            a %= b;
        else 
            b %= a;
    }
    return a + b;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        long long P, Q;
        char ch;
        cin >> P >> ch >> Q;
        long long g = gcd(P, Q);
        P /= g;
        Q /= g;
        long long r = 0;
        while (Q % 2 == 0)
        {
            ++r;
            Q /= 2;
        }
        if (Q != 1)
            cout << "Case #" << t << ": " << "impossible" << endl;
        else
        {
            while (P > 1)
            {
                --r;
                P /= 2;
            }
            cout << "Case #" << t << ": " << r << endl;
        }
    }
    return 0;
}