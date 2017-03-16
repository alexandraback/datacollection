#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int bf(const int e, const int c, const int r, const vector<int>& v, const int pos, const int curgain)
{
    if (pos == (int)v.size())
        return curgain;

    int m = -1;
    for (int i = 0; i <= c; i++)
    {
        int newc = c-i+r;
        if (newc > e)
            newc = e;
        int newgain = curgain + i*v[pos];
        int here = bf(e, newc, r, v, pos+1, newgain);
        if (here > m)
            m = here;
    }
    return m;
}


void solve()
{
    int e, r, n;
    cin >> e >> r >> n;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << bf(e, e, r, v, 0, 0) << endl;
}


int main()
{
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        cout << "Case #" << caseNum << ": ";
        solve();
    }

    return 0;
}
