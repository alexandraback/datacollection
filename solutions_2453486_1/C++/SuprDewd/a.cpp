#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

char arr[4][4];

int winner(int i, int j, int di, int dj)
{
    int a = i, b = j;
    bool x = false, o = false;
    while (i >= 0 && j >= 0 && i < 4 && j < 4)
    {
        if (arr[i][j] == '.')
        {
            return 0;
        }
        else if (arr[i][j] == 'X')
        {
            x = true;
        }
        else if (arr[i][j] == 'O')
        {
            o = true;
        }

        i += di;
        j += dj;
    }

    // printf("%d %d %d %d: %d\n", a,b,di,dj, x && !o ? 1 : !x && o ? 2 : 0);

    return x && !o ? 1 : !x && o ? 2 : 0;
}

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int t = 0; t < n; t++)
    {
        bool left = false;
        string line;
        for (int i = 0; i < 4; i++)
        {
            getline(cin, line);
            for (int j = 0; j < 4; j++)
            {
                arr[i][j] = line[j];
                left = left || arr[i][j] == '.';
            }
        }

        if (t != n-1) getline(cin, line);

        int win = 0; 
        for (int i = 0; i < 4; i++)
        {
            win |= winner(i, 0, 0, 1);
            win |= winner(0, i, 1, 0);
        }

        win |= winner(0, 0, 1, 1);
        win |= winner(0, 3, 1, -1);

        if (win == 3 || (win == 0 && !left))
        {
            printf("Case #%d: Draw\n", t+1);
        }
        else if (win == 1)
        {
            printf("Case #%d: X won\n", t+1);
        }
        else if (win == 2)
        {
            printf("Case #%d: O won\n", t+1);
        }
        else if (win == 0)
        {
            printf("Case #%d: Game has not completed\n", t+1);
        }
    }


    return 0;
}

