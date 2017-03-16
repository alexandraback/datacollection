#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 1000;

int a[N][N];
int b[N][N];

int main(int argc, char* argv[])
{
    int tt;
    cin >> tt;
    forn(tc, tt)
    {
        int n, m;
        
        cin >> n >> m;
        forn(i, n)
            forn(j, m)
                cin >> b[i][j], a[i][j] = 100;
        
        while (true)
        {
            bool updated = false;

            forn(i, n)
            {
                int maxd = 0;
                forn(j, m)
                    maxd = max(maxd, b[i][j]);
                bool u = false;
                forn(j, m)
                    if (a[i][j] > maxd)
                        u = true;
                if (u)
                {
                    forn(j, m)
                        a[i][j] = min(a[i][j], maxd);
                    updated = true;
                }
            }

            forn(j, m)
            {
                int maxd = 0;
                forn(i, n)
                    maxd = max(maxd, b[i][j]);
                bool u = false;
                forn(i, n)
                    if (a[i][j] > maxd)
                        u = true;
                if (u)
                {
                    forn(i, n)
                        a[i][j] = min(a[i][j], maxd);
                    updated = true;
                }
            }

            if (!updated)
                break;
        }

        bool same = true;

        forn(i, n)
            forn(j, m)
                if (a[i][j] != b[i][j])
                    same = false;
        
        cout << "Case #" << (tc + 1) << ": " << (same ? "YES" : "NO") << endl;
    }

    return 0;
}
