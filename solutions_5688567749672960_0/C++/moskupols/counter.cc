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

const int maxn =10000006;
int n;

int range[maxn];
queue<int> q;

int rever(int x)
{
    ostringstream ss;
    ss << x;
    string s = ss.str();
    reverse(ALL(s));
    istringstream iss(s);
    iss >> x;
    return x;
}

void relax(int v, int u)
{
    if (u >= maxn || range[u] != -1)
        return;
    range[u] = range[v] + 1;
    q.push(u);
}

int bfs(int start, int finish)
{
    memset(range, -1, sizeof range);

    range[start] = 1;
    q = queue<int>();
    q.push(start);

    while (!q.empty() && range[finish] == -1)
    {
        int v = q.front();
        q.pop();

        relax(v, v + 1);
        relax(v, rever(v));
    }
    return range[finish];
}

void solve()
{
    cin >> n;
    cout << bfs(1, n) << endl;
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

