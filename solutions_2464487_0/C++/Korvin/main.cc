#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>

#define DEBUG(x) cout << #x << ": " << x << "\n"
using namespace std; // }}}

typedef unsigned long long ulint;

ulint f(ulint n, ulint r)
{
    return (2 * r + 2 * n - 1) * n;
}

ulint result(ulint r, ulint t)
{
    ulint lo = 1, hi = 1;
    while (f(hi, r) <= t) hi*= 2;
    while (lo + 1 != hi) {
        ulint mid = lo + (hi - lo) / 2;
        ulint fmid = f(mid, r);
        if (fmid <= t)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    time_t start, end;
    time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    //cout.precision(6);
    //cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        ulint r, t;
        cin >> r >> t;
        cout << "Case #" << i << ": " << result(r, t) << endl;
        //time(&end);
        //::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
