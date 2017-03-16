#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

double c, x, f;

double cnt(int fn)
{
    //dbg(fn);
    double cur = 2;
    double ret = 0;
    while (fn)
    {
        ret += c / cur;
        cur += f;
        fn--;
    }
    //dbg(x);
    ret += x / cur;
    //dbg(ret);
    return ret;
}

double solve()
{
    int l = 0, r = x;
    while (l < r - 3)
    {
        int fn1 = l + (r - l) / 3, fn2 = r - (r - l) / 3;
        if (cnt(fn1) >= cnt(fn2))
            l = fn1;
        else r = fn2;
    }
    double ret = x;
    for (int i = l; i <= r; i++)
        ret = min(ret, cnt(i));
    return ret;
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> c >> f >> x;
        cout << "Case #" << tc << ": ";
        cout.precision(7);
        cout << fixed << solve();
        cout << endl;
    }
    return 0;
}
