#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>

using namespace std;

long long diff(string const& a, string const& b)
{
    long long aa = atoll(a.c_str());
    long long bb = atoll(b.c_str());

    return abs(aa - bb);
}

string resC, resJ;
long long resDiff;

void bf(int idx, string& c, string& j)
{
    if (idx == c.size())
    {
        long long res = diff(c, j);

        if (res < resDiff || (res == resDiff && c < resC) || (res == resDiff && c == resC && j < resJ))
        {
            resDiff = res;
            resC = c;
            resJ = j;
        }

        return;
    }

    if (c[idx] == '?' && j[idx] == '?')
    {
        for (int a = '0'; a <= '9'; ++a)
            for (int b = '0'; b <= '9'; ++b)
            {
                c[idx] = a;
                j[idx] = b;
                bf(idx + 1, c, j);
            }

        c[idx] = j[idx] = '?';
    }
    else if (c[idx] == '?')
    {
        for (int a = '0'; a <= '9'; ++a)
        {
            c[idx] = a;
            bf(idx + 1, c, j);
        }

        c[idx] = '?';
    }
    else if (j[idx] == '?')
    {
        for (int a = '0'; a <= '9'; ++a)
        {
            j[idx] = a;
            bf(idx + 1, c, j);
        }

        j[idx] = '?';
    }
    else
        bf(idx + 1, c, j);
}

void solve(int idx, string& c, string& j, bool equal, bool cmore)
{
    if (idx == c.size())
    {
        long long res = diff(c, j);

        if (res < resDiff || (res == resDiff && c < resC) || (res == resDiff && c == resC && j < resJ))
        {
            resDiff = res;
            resC = c;
            resJ = j;
        }

        return;
    }

    if (c[idx] == '?' && j[idx] == '?')
    {
        if (equal)
        {
            c[idx] = j[idx] = '0';
            solve(idx + 1, c, j, true, false);
            c[idx] = '1';
            solve(idx + 1, c, j, false, true);
            c[idx] = '0';
            j[idx] = '1';
            solve(idx + 1, c, j, false, false);
        }
        else
        {
            if (cmore)
            {
                c[idx] = '0';
                j[idx] = '9';
            }
            else
            {
                c[idx] = '9';
                j[idx] = '0';
            }

            solve(idx + 1, c, j, false, cmore);
        }

        c[idx] = j[idx] = '?';
        return;
    }

    if (c[idx] == '?' && equal)
    {
        c[idx] = j[idx];
        solve(idx + 1, c, j, true, false);
        if (c[idx] != '9')
        {
            ++c[idx];
            solve(idx + 1, c, j, false, true);
            --c[idx];
        }

        if (c[idx] != '0')
        {
            --c[idx];
            solve(idx + 1, c, j, false, false);
            ++c[idx];
        }
        c[idx] = '?';
        return;
    }
    else if (c[idx] == '?')
    {
        if (cmore)
            c[idx] = '0';
        else
            c[idx] = '9';

        solve(idx + 1, c, j, false, cmore);
        c[idx] = '?';
        return;
    }

    if (j[idx] == '?' && equal)
    {
        j[idx] = c[idx];
        solve(idx + 1, c, j, true, false);
        if (j[idx] != '9')
        {
            ++j[idx];
            solve(idx + 1, c, j, false, false);
            --j[idx];
        }

        if (j[idx] != '0')
        {
            --j[idx];
            solve(idx + 1, c, j, false, true);
            ++j[idx];
        }
        j[idx] = '?';
        return;
    }
    else if (j[idx] == '?')
    {
        if (cmore)
            j[idx] = '9';
        else
            j[idx] = '0';

        solve(idx + 1, c, j, false, cmore);
        j[idx] = '?';
        return;
    }

    if (c[idx] != '?' && j[idx] != '?')
    {
        if (!equal)
            solve(idx + 1, c, j, false, cmore);
        else if (c[idx] == j[idx])
            solve(idx + 1, c, j, true, false);
        else
            solve(idx + 1, c, j, false, c[idx] > j[idx]);
    }

}

int main()
{
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        resDiff = numeric_limits<long long>::max();
        resC = resJ = "";
        string c, j;
        cin >> c >> j;

        //bf(0, c, j);
        solve(0, c, j, true, false);


        printf("Case #%d: ", CASE);
        cout << resC << " " << resJ << endl;
    }


    return 0;
}
