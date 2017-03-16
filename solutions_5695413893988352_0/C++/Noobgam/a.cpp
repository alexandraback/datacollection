#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

bool gen(string &val, string &key)
{
    for (int i = val.length() - 1; i >= 0; --i)
        if (key[i] == '?')
            if (val[i] != '9')
            {
                ++val[i];
                for (int j = i + 1; j < val.length(); ++j)
                    if (key[j] == '?')
                        val[j] = '0';
                return true;
            }
    return false;
}

int cast(string s)
{
    int cur = 0;
    int deg = 1;
    while (!s.empty())
    {
        cur += (s.back() - '0') * deg;
        deg *= 10;
        s.pop_back();
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        string s, t;
        cin >> s >> t;
        int ans = 1000000;
        string besta, bestb;
        string a = s, b = t;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == '?')
                a[i] = '0';
        for (; ;)
        {
            b = t;
            for (int i = 0; i < b.length(); ++i)
                if (b[i] == '?')
                    b[i] = '0';
            for (; ; )
            {
                int score1, score2;
                score1 = cast(a);
                score2 = cast(b);
                if (ans > abs(score1 - score2))
                    ans = abs(score1 - score2),
                    besta = a,
                    bestb = b;
                //should minimize itself fine
            if (!gen(b, t))
                break;
            }
            if (!gen(a, s))
                break;
        }
        cout << "Case #" << test + 1 << ": ";
        cout << besta << " " << bestb << endl;
    }

    return 0;
}