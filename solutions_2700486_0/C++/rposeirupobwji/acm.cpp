#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <map>
#include <stack>
#include <ctime>
#include <cstring>
#include <cassert>

typedef signed char int8;
typedef unsigned char uint8;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

#define mp(a, b) std::make_pair(a, b)
using namespace std;

int rek(int l, int r, int t)
{
    if (!t)
        return 1;

    int res = 0;
    if (l)
        res += rek(l - 1, r, t - 1);

    if (r)
        res += rek(l, r - 1, t - 1);

    return res;
}

int main()
{
    int T;
    cin >> T;

    map<int, int> layers;

    int dia = 1;
    int d = 2;
    while (dia <= 2000000)
    {
        layers.insert(mp(dia, d - 2));
        dia += d * 2 + 1;
        d += 2;
    }

    vector<double> tab;
    tab.push_back(0.5);
    for (int i = 1; i < 15000; ++i)
        tab.push_back(tab[i - 1] * 0.5);

    for (int CASE = 1; CASE <= T; ++CASE)
    {
        printf("Case #%d: ", CASE);
        int n, x, y;
        cin >> n >> x >> y;
        x = abs(x);

        auto itr = layers.lower_bound(n);

        if (itr->first == n)
        {
            if (x + y <= itr->second)
                printf("%.1f\n", 1.0);
            else
                printf("%.1f\n", 0.0);

            continue;
        }

        if (itr->second < x + y)
        {
            printf("%.1f\n", 0.0);
            continue;
        }

        --itr;

        if (itr->second >= x + y)
        {
            printf("%.1f\n", 1.0);
            continue;
        }

        n -= itr->first;
        assert(n > 0);

        if (y > n || x == 0)
        {
            printf("%.1f\n", 0.0);
            continue;
        }

        ++itr;

        if (n > itr->second)
        {
            if (n - itr->second > y)
            {
                printf("%.1f\n", 1.0);
                continue;
            }
        }

        uint64 a = 1;
        uint64 b = 2;

        for (int i = 1; i < n; ++i)
        {
            int q = i;
            int w = n - i;

            int m = rek(q, w, n);

            if (q >= (y+1))
                a += m;

            b += m;
        }

        cout << a / (long double)b << endl;
    }

    return 0;
}
