// License {{{
// Copyright © 2016 Fedor Alekseev <feodor.alexeev@gmail.com>
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
// }}}

#include <bits/stdc++.h>
using namespace std;

#ifdef moskupols
    #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 42
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC)

#define WHOLE(v) begin(v),end(v)
#define RWHOLE(v) (v).rbegin(),(v).rend()
#define UNIQUE(v) (v).erase(unique(WHOLE(v)),(v).end())

typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

const int maxn = 20;

int id[maxn][2];

int n;

bool check(int mask)
{
    unordered_set<int> covered[2];

    for (int i = 0; i < n; ++i)
        if (!((mask>>i)&1))
            for (int j = 0; j < 2; ++j)
                covered[j].insert(id[i][j]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j)
            if (!covered[j].count(id[i][j]))
                return false;
    return true;
}

void solve()
{
    cin >> n;

    unordered_map<string, int> idmap;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j)
        {
            string s;
            cin >> s;

            if (!idmap.count(s))
            {
                size_t sz = idmap.size();
                idmap[s] = sz;
            }
            id[i][j] = idmap[s];
        }

    int ans = 0;
    for (int mask = 0; mask < (1<<n); ++mask)
        if (check(mask))
            ans = max(ans, __builtin_popcount(mask));

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
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

