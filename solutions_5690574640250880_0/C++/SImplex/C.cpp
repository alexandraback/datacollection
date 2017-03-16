#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
#include <iomanip>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)


int main() {
    ios_base::sync_with_stdio(false);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T = 0;
    cin >> T;
    forn(Case,T)
    {
        int r,c,m;
        cin >> r >> c >> m;
        cout << "Case #" << Case + 1 << ":\n";
        if (r == 1)
        {
            cout << 'c';
            forn(i, c - m - 1)
                cout << '.';
            forn(i,m)
                cout << '*';
            cout << "\n";
            continue;
        }
        if (c == 1)
        {
            cout << "c\n";
            forn(i, r-m-1)
                cout << ".\n";
            forn(i,m)
                cout << "*\n";
            continue;
        }
        int tmp = c*r-m;
        if (tmp == 1)
        {
            forn(i, r)
            forn(j, c)
            {
                if (j == 0 && i == 0)
                    cout << 'c';
                else
                    cout << '*';
                if (j == c - 1)
                    cout << "\n";
            }
            continue;
        }
        if (r*c - 3 <= m || ( (r == 2 || c == 2) && m%2 == 1))
        {
            cout << "Impossible\n";
            continue;
        }
        if (r == 3 && c == 3 && m == 2)
        {
            cout << "Impossible\n";
            continue;
        }
        if (tmp == 5 || tmp == 7)
        {
            cout << "Impossible\n";
            continue;
        }

        int resti = (m+2)/2;
        int restj = (m+1)/2;

        for(int wid = 2; wid <= c; ++wid)
            for (int hei = 2; hei <= r; ++hei)
            {
                int rest = tmp - wid*hei;
                if (rest < 0 || rest >= max(wid, hei))
                    continue;
                if (wid*hei == tmp)
                {
                    forn(i, r)
                        forn(j, c)
                        {
                            if (i == 0 && j == 0)
                            {
                                cout << 'c';
                                continue;
                            }
                            if (i < hei && j < wid)
                                cout << '.';
                            else
                                cout << '*';
                            if (j == c - 1)
                                cout << "\n";
                        }
                    goto lab;
                }
                if (wid < c && rest >= 2 && rest < hei)
                {
                    forn(i, r)
                    forn(j, c)
                    {
                        if (i == 0 && j == 0)
                        {
                            cout << 'c';
                            continue;
                        }
                        if ((i < hei && j < wid) || (j == wid && i < rest))
                            cout << '.';
                        else
                            cout << '*';
                        if (j == c - 1)
                            cout << "\n";
                    }
                    goto lab;
                }
                if (hei < r && rest >= 2 && rest < wid)
                {
                    forn(i, r)
                    forn(j, c)
                    {
                        if (i == 0 && j == 0)
                        {
                            cout << 'c';
                            continue;
                        }
                        if ((i < hei && j < wid) || (i == hei && j < rest))
                            cout << '.';
                        else
                            cout << '*';
                        if (j == c - 1)
                            cout << "\n";
                    }
                    goto lab;
                }
            }
        if (resti <= r && restj <= c)
        forn(i,r)
            forn(j,c)
            {
                if (i == 0 && j == 0)
                {
                    cout << 'c';
                    continue;
                }
                if ((i == r-1 && j >= c-restj) || (j == c-1 && i >= c - resti))
                    cout << '*';
                else
                    cout << '.';
                if (j == c-1)
                    cout << "\n";
            }
        goto lab;
lab:
    ;
    }
    return 0;
}
