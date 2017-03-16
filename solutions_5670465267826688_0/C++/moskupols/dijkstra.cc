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

typedef pair<int, int> quart;

const quart combined[4][4] =
{
    {{1, 1}, {1, 2}, {1, 3}, {1, 4}},
    {{1, 2}, {-1, 1}, {1, 4}, {-1, 3}},
    {{1, 3}, {-1, 4}, {-1, 1}, {1, 2}},
    {{1, 4}, {1, 3}, {-1, 2}, {-1, 1}},
};

quart combine(quart a, quart b)
{
    quart ret = combined[a.second-1][b.second-1];
    ret.first *= a.first * b.first;
    return ret;
}

quart toQuart(char c)
{
    return quart(1, c == 'i' ? 2 : c == 'j' ? 3 : 4);
}

int l, x;
string s;

bool loopit(int &i, int &j, quart desired)
{
    quart cur(1, 1);
    bool first = true;
    for (; i < x; ++i)
    {
        if (!first)
            j = 0;
        first = false;
        for (; cur != desired && j < l; ++j)
            cur = combine(cur, toQuart(s[j]));
        if (cur == desired)
            return true;
    }
    return false;
}

void solve()
{
    cin >> l >> x;
    cin >> s;

    int i = 0, j = 0;

    if (loopit(i, j, quart(1, 2))
            && loopit(i, j, quart(1, 3))
            && loopit(i, j, quart(1, 4)))
    {
        quart cur(1, 1);
        bool first = true;
        for (; i < x; ++i)
        {
            if (!first)
                j = 0;
            first = false;
            for (; j < l; ++j)
                cur = combine(cur, toQuart(s[j]));
        }
        if (cur == quart(1, 1))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    cin.sync_with_stdio(false);
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

