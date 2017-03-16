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


const double kPI = acos(-1.0);


void solve()
{
    double r, t;
    cin >> r >> t;

    int i;
    for (i = 0; true; i++)
    {
        double y = r+2*i;
        double x = y+1.0;
        double req = (x*x - y*y);
        if (t < req)
            break;
        t -= req;
    }

    cout << i << endl;
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
