#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
llint const INF = 0x3fffffffffffffffLL;
llint f(int p, string const &C, string const &J,
        string &x, string &y, llint &u, llint &v)
{
    // rc > rj (strictly)
    int n = C.size();
    x = string(C);
    y = string(J);
    // equal
    for (int i = 0; i < p; ++i)
    {
        if (x[i] == '?' && y[i] == '?')
        {
            x[i] = '0';
            y[i] = '0';
        }
        else if (x[i] == '?')
        {
            x[i] = y[i];
        }
        else if (y[i] == '?')
        {
            y[i] = x[i];
        }
        else if (x[i] != y[i])
        {
            return INF;
        }
    }
    if (p == n)
    {
        return 0;
    }
    // gt
    {
        if (x[p] == '?' && y[p] == '?')
        {
            x[p] = '1';
            y[p] = '0';
        }
        else if (x[p] == '?')
        {
            if (y[p] == '9')
            {
                return INF;
            }
            x[p] = y[p] + 1;
        }
        else if (y[p] == '?')
        {
            if (x[p] == '0')
            {
                return INF;
            }
            y[p] = x[p] - 1;
        }
        else if (x[p] <= y[p])
        {
            return INF;
        }
    }
    // lt
    for (int i = p + 1; i < n; ++i)
    {
        if (x[i] == '?')
        {
            x[i] = '0';
        }
        if (y[i] == '?')
        {
            y[i] = '9';
        }
    }
    // result
    sscanf(x.c_str(), "%I64d", &u);
    sscanf(y.c_str(), "%I64d", &v);
    return u - v;
}
void work(string const &C, string const &J, string &x, string &y)
{
    llint r = INF, u = INF, v = INF;
    string tx, ty;
    llint tu, tv;
    llint val;
    for (string::size_type p = 0; p <= C.size(); ++p)
    {
        val = f(p, C, J, tx, ty, tu, tv);
        if (val < r || (val == r && (tu < u || (tu == u && tv < v))))
        {
            r = val;
            u = tu;
            v = tv;
            x = tx;
            y = ty;
        }
        val = f(p, J, C, ty, tx, tv, tu);
        if (val < r || (val == r && (tu < u || (tu == u && tv < v))))
        {
            r = val;
            u = tu;
            v = tv;
            x = tx;
            y = ty;
        }
    }
}
int main()
{
    int tc;
    string c, j;
    string x, y;
    cin >> tc;
    for (int cc = 1; cc <= tc; ++cc)
    {
        cin >> c >> j;
        work(c, j, x, y);
        printf("Case #%d: %s %s\n", cc, x.c_str(), y.c_str());
    }
    return 0;
}
