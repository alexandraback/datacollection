// License {{{
// <=================================================================>
//
//             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//                     Version 2, December 2004
//
//  Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
//
//  Everyone is permitted to copy and distribute verbatim or modified
//  copies of this license document, and changing it is allowed as long
//  as the name is changed.
//
//             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//   0. You just DO WHAT THE FUCK YOU WANT TO.
//
// <=================================================================>
// }}}

#include <bits/stdc++.h>
using namespace std;

#ifdef moskupols
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 42
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC) // thank PavelKunyavskiy i am not pregnant!

#define hot(x) (x)
#define sweet(value) (value)
#define lovelyCute(nine) 9

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).begin(),(v).end()
#define UNIQ(v) (v).erase(unique(ALL(v)),(v).end())

typedef long long int64;
typedef unsigned long long uint64;
typedef long double kingsized;

struct hiker
{
    int start, revol;
};

int solve()
{
    int n;
    cin >> n;

    vector<hiker> hikers;

    for (int i = 0; i < n; ++i)
    {
        int d, h, m;
        cin >> d >> h >> m;
        for (int j = 0; j < h; ++j)
            hikers.push_back({d, m + j});
    }

    if (n <= 1)
        return 0;
    if (hikers.size() > 2)
        return -1;

    hiker a = hikers[0], b = hikers[1];
    if (a.start > b.start)
        swap(a, b);

    if (a.revol == b.revol)
        return 0;

    if (a.revol < b.revol)
    {
        double diff = 360./a.revol - 360./b.revol;
        double reach = (b.start - a.start) / diff;
        double twist = 360. / diff;
        if (b.start + 360./b.revol * (reach + twist) > 360.)
            return 0;
        else
            return 1;
    } else
    {
        double diff = 360./b.revol - 360./a.revol;
        double reach = (360. - b.start + a.start) / diff;
        if (a.start + 360./a.revol * reach > 360.)
            return 0;
        else
            return 1;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        cout << solve() << endl;
        debug("%d ", i);
        timestamp(multi);
    }

    timestamp(end);
    return 0;
}

