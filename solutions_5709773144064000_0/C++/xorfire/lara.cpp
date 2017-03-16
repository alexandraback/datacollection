#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cout << fixed << setprecision(10);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        long double c, f, x;
        cin >> c >> f >> x;
        int hi = int(x / c) + 1000;

        long double ret = x / 2, sum = x / 2;
        for(int n = 1; n <= hi; ++n)
        {
            sum += c / (2 + (n-1) * f);
            sum -= x / (2 + (n-1) * f);
            sum += x / (2 + n * f);
            ret = min(ret, sum);
        }

        cout << "Case #" << tt << ": " << ret;
        if(tt < t) puts("");
    }
    return 0;
}