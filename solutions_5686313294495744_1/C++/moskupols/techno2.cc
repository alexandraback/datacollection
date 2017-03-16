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

#define WHOLE(v) (v).begin(),(v).end()
#define RWHOLE(v) (v).rbegin(),(v).rend()
#define UNIQUE(v) (v).erase(unique(WHOLE(v)),(v).end())

typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;


const int maxn = 3005;
const int maxe = maxn * 4;

int edges[maxn][2];
int degree[2][maxn];

int ne[maxe], to[maxe], cap[maxe];
int head[maxn];
int esz;

const int source = 0, sink = 1;

void addEdge(int a, int b, int c)
{
    assert(esz < maxe);

    ne[esz] = head[a];
    to[esz] = b;
    cap[esz] = c;
    head[a] = esz++;

    ne[esz] = head[b];
    to[esz] = a;
    cap[esz] = 0;
    head[b] = esz++;
}

int used[maxn];
int q;

int dfs(int v)
{
    if (v == sink)
        return 1;
    if (used[v] == q)
        return 0;
    used[v] = q;
    for (int e = head[v]; e != -1; e = ne[e])
        if (cap[e] > 0)
        {
            if (dfs(to[e]))
            {
                --cap[e];
                ++cap[e^1];
                return 1;
            }
        }
    return 0;
}

int maxFlow()
{
    int ans = 0;
    memset(used, 0, sizeof used);
    for (q = 1; dfs(source); ++q)
        ++ans;
    return ans;
}

int getId(const string &s, unordered_map<string, int> &idmap)
{
    if (!idmap.count(s))
    {
        size_t sz = idmap.size();
        idmap[s] = sz;
        return sz;
    }
    return idmap[s];
}

void solve()
{
    int n;
    cin >> n;

    unordered_map<string, int> idmap[2];
    memset(degree, 0, sizeof degree);

    for (int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        int ia = getId(a + "_1", idmap[0]);
        int ib = getId(b + "_2", idmap[1]);

        edges[i][0] = ia;
        edges[i][1] = ib;

        ++degree[0][ia];
        ++degree[1][ib];
    }
    size_t s0 = idmap[0].size();
    size_t s1 = idmap[1].size();

    esz = 0;
    memset(head, -1, sizeof head);

    for (int i = 0; i < s0; ++i)
        addEdge(source, 2 + i, degree[0][i] - 1);
    for (int i = 0; i < s1; ++i)
        addEdge(2 + s0 + i, sink, degree[1][i] - 1);
    for (int i = 0; i < n; ++i)
        addEdge(2 + edges[i][0], 2 + s0 + edges[i][1], 1);

    cout << maxFlow() << '\n';
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

