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

char win(vector<string>& f, int x, int y, int dx, int dy)
{
    set<char> cc;
    
    forn(i, 4)
    {
        if (x < 0 || x >= 4 || y < 0 || y >= 4)
            return 0;

        if (f[x][y] == '.')
            return 0;

        cc.insert(f[x][y]);

        x += dx;
        y += dy;
    }

    if (cc.size() == 1)
        return *cc.begin();
    else
    {
        if (cc.size() == 2 && cc.count('T'))
        {
            cc.erase('T');
            return *cc.begin();
        }
    }

    return 0;
}

int main(int argc, char* argv[])
{
    int tt;
    cin >> tt;
    forn(tc, tt)
    {
        vector<string> f(4);
        forn(i, 4)
            cin >> f[i];

        set<char> wins;
        forn(i, 4)
            forn(j, 4)
                for (int dx = -1; dx <= 1; dx++)
                    for (int dy = -1; dy <= 1; dy++)
                        if ((dx != 0 || dy != 0) && win(f, i, j, dx, dy))
                            wins.insert(win(f, i, j, dx, dy));

        string result;
        if (wins.size() == 1)
            result = *wins.begin() + string(" won");
        else
        {
            result = "Draw";
            forn(i, 4)
                forn(j, 4)
                    if (f[i][j] == '.')
                        result = "Game has not completed";
        }

        cout << "Case #" << (tc + 1) << ": " << result << endl; 
    }

    return 0;
}
