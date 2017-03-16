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
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        int r, c, m;
        cin >> r >> c >> m;

        bool imp = false, swp = (c < r);
        if(swp) swap(c, r);

        char a[r][c];
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                a[i][j] = '*';

        int u = r * c - m;
        if(u == 1)
            a[0][0] = '.';
        else if(r == 1)
        {
            for(int i = 0; i < u; ++i)
                a[0][i] = '.';
        }
        else if(r == 2)
        {
            if(u < 4 or u & 1) imp = true;
            else
                for(int i = 0; i < (u / 2); ++i)
                    a[0][i] = a[1][i] = '.';
        }
        else if(c == 3)
        {
            if(u < 4) imp = true;
            else if(u < 9 and u & 1) imp = true;
            else
            {
                a[0][0] = a[0][1] = a[1][0] = a[1][1] = '.';
                if(u > 4) a[0][2] = a[1][2] = '.';
                if(u > 6) a[2][0] = a[2][1] = '.';
                if(u > 8) a[2][2] = '.';
            }
        }
        else if(u >= 2 * c)
        {
            int p = u / c, q = u % c;
            for(int i = 0; i < p; ++i)
                for(int j = 0; j < c; ++j)
                    a[i][j] = '.';
            for(int j = 0; j < q; ++j)
                a[p][j] = '.';

            if(q == 1)
            {
                if(p % 2 == 0)
                {
                    a[p][1] = a[p][2] = '.';
                    a[p-2][c-1] = a[p-1][c-1] = '*';
                }
                else
                {
                    a[p][1] = '.';
                    a[p-1][c-1] = '*';
                }
            }
        }
        else if(u % 2 == 0)
        {
            if(u == 2) imp = true;
            else
                for(int i = 0; i < (u / 2); ++i)
                    a[0][i] = a[1][i] = '.';
        }
        else if(u < 9)
            imp = true;
        else
        {
            for(int i = 0; i < 3; ++i)
                for(int j = 0; j < 3; ++j)
                    a[i][j] = '.';
            u -= 9;
            for(int i = 3; i < 3 + (u / 2); ++i)
                a[0][i] = a[1][i] = '.';
        }

        cout << "Case #" << tt << ":\n";
        if(imp) cout << "Impossible\n";
        else if(swp == false)
        {
            a[0][0] = 'c';
            for(int i = 0; i < r; ++i)
            {
                for(int j = 0; j < c; ++j)
                    cout << a[i][j];
                cout << '\n';
            }
        }
        else
        {
            a[0][0] = 'c';
            for(int i = 0; i < c; ++i)
            {
                for(int j = 0; j < r; ++j)
                    cout << a[j][i];
                cout << '\n';
            }
        }
    }
    return 0;
}