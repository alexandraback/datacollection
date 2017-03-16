#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 45;

long long Pow[N];

long long gcd(long long a, long long b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    long long p, q;

    cin >> t;

    Pow[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        Pow[i] = Pow[i-1]<<1;
    }

    for (int i = 1; i <= t; ++i)
    {
        scanf("%lld/%lld", &p, &q);
        long long gcdt = gcd(q, p);
        if (p > q)
        {
            cout << "Case #" << i << ": " << "impossible" << endl;
            continue;
        }
        if (p == q)
        {
            cout << "Case #" << i << ": " << 0 << endl;
            continue;
        }
        p /= gcdt;
        q /= gcdt;
        int index = -1;
        for (int j = 0; j < N; ++j)
        {
            if (q == Pow[j])
            {
                index = j;
                break;
            }
        }
        if (index == -1 || index >= 41)
        {
            cout << "Case #" << i << ": " << "impossible" << endl;
            continue;
        }
        double tmp = (double)q/p;
        for (int j = 0; j < N; ++j)
        {
            if (tmp <= Pow[j])
            {
                index = j;
                break;
            }
        }
        cout << "Case #" << i << ": " << index << endl;
    }
    return 0;
}

