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

bool better(const pair<int, int> &a, const pair<int, int> &b)
{
    return make_tuple(abs(a.first - a.second), a.first, a.second) <
        make_tuple(abs(b.first - b.second), b.first, b.second);
}

bool valid(int x, const string &s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        int c = x % 10;
        if (s[i] != '?' && s[i] - '0' != c)
            return false;
        x /= 10;
    }
    return x == 0;
}

string scorify(int x, size_t n)
{
    string s("00000000");
    s += to_string(x);
    return s.substr(s.size() - n);
}

void solve()
{
    string t, s;
    cin >> t >> s;

    reverse(WHOLE(t));
    reverse(WHOLE(s));

    int pa = 1;
    for (size_t i = 0; i < t.size(); ++i)
        pa *= 10;

    int pb = 1;
    for (size_t i = 0; i < s.size(); ++i)
        pb *= 10;

    pair<int, int> ans(1<<30, 0);
    for (int i = 0; i < pa; ++i)
        if (valid(i, t))
            for (int j = 0; j < pb; ++j)
                if (valid(j, s))
                    ans = min(ans, make_pair(i, j), better);

    cout << scorify(ans.first, t.size()) << ' ' << scorify(ans.second, s.size()) << endl;
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

