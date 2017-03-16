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

#define hot(x) (x)
#define sweet(value) (value)
#define faceless

#define WHOLE(v) (v).begin(),(v).end()
#define RWHOLE(v) (v).rbegin(),(v).rend()
#define UNIQUE(v) (v).erase(unique(WHOLE(v)),(v).end())

typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

const int maxn = 1005;

int cycle(int start, const vector<int> &bff)
{
    int ret = 0;
    unordered_set<int> met;
    int v;
    for (v = start; !met.count(v); v = bff[v])
    {
        ++ret;
        met.insert(v);
    }
    return (v == start ? ret : 0);
}

vector<vector<int>> inverseBff(const vector<int> &bff)
{
    vector<vector<int>> ret(bff.size());
    for (size_t i = 0; i < bff.size(); ++i)
        ret[bff[i]].push_back(i);
    return ret;
}

int deepestTail(int start, int ignore, vector<vector<int>> &edges)
{
    static int range[maxn];
    memset(range, -1, sizeof range);
    queue<int> q;

    range[start] = range[ignore] = 0;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int u : edges[v])
        {
            if (range[u] == -1)
            {
                range[u] = range[v] + 1;
                q.push(u);
            }
        }

        if (q.empty())
            return range[v];
    }
    assert(false);
}

int fitTwoCycles(const vector<int> &bff)
{
    int n = bff.size();
    auto back = inverseBff(bff);

    int ret = 0;

    for (int a = 0; a < n; ++a)
    {
        int b = bff[a];
        if (a < b && bff[b] == a)
            ret += 2 + deepestTail(a, b, back) + deepestTail(b, a, back);
    }

    return ret;
}

void solve()
{
    int n;

    cin >> n;
    vector<int> f(n);
    for (int& x : f)
    {
        cin >> x;
        --x;
    }

    vector<int> cnt(n + 1);

    int maxCycle = 0;

    for (int i = 0; i < n; ++i)
        maxCycle = max(maxCycle, cycle(i, f));

    cout << max(maxCycle, fitTwoCycles(f)) << '\n';
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

