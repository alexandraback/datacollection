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

int X, Y, N;
int* highest = new int[25000];

double bt(int at, int curx, int cury)
{
    // for (int i = 12000 - 4; i <= 12000 + 4; i++)
    // {
    //     printf("%d ", highest[i]);
    // }

    // printf("\n");

    if (at == N)
    {
        return 0;
    }
    else if (cury == 0)
    {
        if (curx == X && cury == Y)
        {
            return 1.0;
        }

        int last = highest[curx];
        highest[curx] = cury;
        double r = bt(at + 1, 0 + 12000, highest[0 + 12000] + 2);
        highest[curx] = last;
        return r;
    }
    else
    {
        bool left = highest[curx - 1] + 1 == cury,
             right = highest[curx + 1] + 1 == cury;

        // printf("%d %d\n", left ? 1 : 0, right ? 1 : 0);
        if (left && right)
        {
            if (curx == X && cury == Y)
            {
                return 1.0;
            }

            int last = highest[curx];
            highest[curx] = cury;
            double r = bt(at + 1, 0 + 12000, highest[0 + 12000] + 2);
            highest[curx] = last;
            return r;
        }
        else if (left)
        {
            return bt(at, curx + 1, cury - 1);
        }
        else if (right)
        {
            return bt(at, curx - 1, cury - 1);
        }
        else
        {
            return 0.5 * bt(at, curx - 1, cury - 1) + 0.5 * bt(at, curx + 1, cury - 1);
        }
    }
}

int main()
{
    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
        for (int i = 0; i < 25000; i++) highest[i] = -2;
        scanf("%d %d %d\n", &N, &X, &Y);
        X += 12000;
        double r = bt(0, 0 + 12000, highest[0 + 12000] + 2);
        printf("Case #%d: %lf\n", t+1, r);
    }

    return 0;
}
