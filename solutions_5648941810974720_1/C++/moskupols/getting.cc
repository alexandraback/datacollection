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

string words[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
pair<int, char> unambig[10] =
{
    {0, 'Z'},
    {6, 'X'},
    {2, 'W'},
    {8, 'G'},
    {3, 'H'},
    {4, 'R'},
    {5, 'F'},
    {7, 'V'},
    {1, 'O'},
    {9, 'E'}
};

void solve()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s)
        ++mp[c];

    map<int, int> ans;
    for (pair<int, char> pic : unambig)
    {
        int cnt = mp[pic.second];
        ans[pic.first] = cnt;
        for (char c : words[pic.first])
            mp[c] -= cnt;
    }

    for (auto&& p : ans)
        for (int i = 0; i < p.second; ++i)
            cout << p.first;
    cout << endl;
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

