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

int a[1005], b[1005];

int main()
{
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i)
        {
            double x; cin >> x;
            a[i] = x * 100000;
        }
        for(int i = 0; i < n; ++i)
        {
            double x; cin >> x;
            b[i] = x * 100000;
        }
        sort(a, a + n);
        sort(b, b + n);

        int ret1 = 0, ret2 = 0;

        int p1 = 0, p2 = 0;
        while(p1 < n)
        {
            while(p2 < n and b[p2] < a[p1]) ++p2;
            if(p2 < n) ++p2;
            else ++ret1;
            ++p1;
        }


        p1 = n - 1, p2 = n - 1;
        while(p1 >= 0)
        {
            while(p2 >= 0 and b[p2] > a[p1]) --p2;
            if(p2 >= 0) ++ret2, --p2;
            --p1;
        }

        cout << "Case #" << tt << ": " << ret2 << ' ' << ret1 << '\n';
    }
    return 0;
}