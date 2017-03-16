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

map<int64, int64> range;
set<pair<int64, int64>> grey;

const int maxp = 16;

int64 powers10[maxp];
const int64 ranges[maxp] = {
    1, 10, 100, 209, 408, 1507, 3506, 14505, 34504, 
    144503, 344502, 1444501, 3444500, 14444499, 34444498, 144444497,};

int64 rever(int64 x)
{
    ostringstream ss;
    ss << x;
    string s = ss.str();
    reverse(ALL(s));
    istringstream iss(s);
    iss >> x;
    return x;
}

int64 toint(string s)
{
    int64 x;
    istringstream iss(s);
    iss >> x;
    return x;
}

// void relax(int64 v, int64 u, int64 add)
// {
    // if (range.count(u) && range[u] <= range[v])
        // return;
    // grey.erase(make_pair(range[u], u));
    // range[u] = range[v] + add;
    // grey.insert(make_pair(range[u], u));
// }

// void bfs(int start)
// {
    // range.clear();
    // grey.clear();

    // range[start] = 1;
    // grey.insert({1, start});

    // while (!grey.empty())
    // {
        // int64 v = grey.begin()->second;
        // grey.erase(grey.begin());

        // int p10 = lower_bound(powers10, powers10 + maxp, v) - powers10;
        // if (p10 == maxp)
            // continue;
        // if (powers10[p10] == v)
        // {
            // ranges[p10] = range[v];
            // for (int i = 1; i < p10; ++i)
            // {
                // int64 u = v + powers10[i] - 1;
                // relax(v, u, u - v);
            // }
            // if (p10 < maxp-1)
                // relax(v, powers10[p10+1], powers10[p10+1] - v);
        // }
        // relax(v, powers10[p10], powers10[p10] - v);
        // relax(v, rever(v), 1);
    // }
// }

void solve()
{
    string ns;
    cin >> ns;

    if (ns.size() == 1)
    {
        cout << ns << endl;
        return;
    }

    int64 ret = ranges[ns.size() - 1];

    int64 left = toint(ns.substr(0, (ns.size()+1) / 2));
    int64 right = toint(ns.substr((ns.size() +1) / 2));

    if (right != 0)
        ret += min(rever(left) + 1 + right - 1, toint(ns) - powers10[ns.size() - 1]);
    else
        ret += rever(left - 1) + 1 + powers10[ns.size()/2] - 1;
    cout << ret << endl;
}

int main()
{
    cin.sync_with_stdio(false);

    powers10[0] = 1;
    for (int i = 1; i < maxp; ++i)
        powers10[i] = powers10[i-1] * 10LL;

    // bfs(1);
    // for (int i = 0; i < maxp; ++i)
        // cerr << ranges[i] << ", ";
    // cerr << endl;
    // return 0;

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        debug("%d ", i);
        timestamp(multi);
    }

    timestamp(end);
    return 0;
}

