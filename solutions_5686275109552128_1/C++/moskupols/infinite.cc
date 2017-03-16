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

const int maxd = 1005;
int d;
int maxp;
int p[maxd];
int64 dp[maxd];

int64 ok(int time)
{
    for (int i = 0; i <= maxp; ++i)
    {
        if (i <= time)
        {
            dp[i] = 0;
            continue;
        }
        dp[i] = 1 << 26;
        for (int j = 0; j * 2 <= i; ++j)
            dp[i] = min(dp[i], 1 + dp[j] + dp[i-j]);
    }
    int64 ret = 0;
    for (int i = 0; i < d; ++i)
        ret += dp[p[i]];
    return ret;
}

void solve()
{
    cin >> d;
    for (int i = 0; i < d; ++i)
        cin >> p[i];

    maxp = *max_element(p, p + d);

    int64 ans = maxp;
    for (int i = 1; i < ans; ++i)
        ans = min(ans, i + ok(i));

    cout << ans << endl;
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
    }

    timestamp(end);
    return 0;
}

