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

map< pair< pair<int, int> , int>, long long > m;

int f(int a, int b, int k)
{
    if(a * b == 0) return a + b + 1;
    if(m.count(make_pair(make_pair(a, b), k)))
        return m[make_pair(make_pair(a, b), k)];

    long long& ret = m[make_pair(make_pair(a, b), k)];
    ret = 0;

    for(int ls1 = 0; ls1 < 2; ++ls1)
        if(ls1 <= a)
            for(int ls2 = 0; ls2 < 2; ++ls2)
                if(ls2 <= b)
                    if((ls1 & ls2) <= k)
                        ret += f((a-ls1) / 2, (b-ls2) / 2, (k-(ls1 & ls2)) / 2);
    return ret;
}

int main()
{
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        cerr << "Executing Case #" << tt << "\n";
        cout << "Case #" << tt << ": ";

        int a, b, k;
        cin >> a >> b >> k;
        cout << f(a-1, b-1, k-1);

        cout << "\n";
    }
    return 0;
}