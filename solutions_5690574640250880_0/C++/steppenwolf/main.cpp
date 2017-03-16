#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int R, C, M;
    cin >> R >> C >> M;
    vector<string> grid(R, string(C, '*'));
    int freeNum = R * C - M;

    bool cut = false;
    int baseNum = -1;
    for (int base = 2; base <= C && baseNum == -1; ++base)
    {
        int height = freeNum / base;
        if (height <= 1 || height > R || (height == R && (freeNum % base))) continue;
        if (freeNum % base != 1)
        {
            baseNum = base;
        }
        else
        {
            if (base == 2) continue;
            if (height >= 3) {
                cut = true;
                baseNum = base;
            }
        }
    }

    bool print = true;
    if (baseNum == -1 && freeNum != 1 && R != 1 && C != 1)
    {
        cout << "Impossible" << endl;
        print = false;
    }
    else if (freeNum > 1)
    {
        if (R == 1)
        {
            baseNum = C;
            cut = false;
        }
        else if (C == 1)
        {
            baseNum = 1;
            cut = false;
        }


        int height = freeNum / baseNum;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < baseNum; ++j)
            {
                grid[i][j] = '.';
            }
        }
        int mod = freeNum % baseNum;

        for (int i = 0; i < mod; ++i)
        {
            grid[height][i] = '.';
        }

        if (cut)
        {
            grid[height -1][baseNum - 1] = '*';
            grid[height][mod] = '.';
        }
    }

    grid[0][0] = 'c';

    if (print)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            cout << grid[i] << endl;
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test)
    {
        cout << "Case #" << test << ":" << endl;
        solve();
    }

    return 0;
        }
