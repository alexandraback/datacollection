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

map<ii, double> mem;
int height;
double prob(int h, int left, int l, int r)
{
    // printf("%d %d %d %d, %d\n", h, left, l, r, height);
    if (l == h+1)
    {
        return 1.0;
    }
    else if (left == 0)
    {
        return 0.0;
    }
    else if (mem.find(ii(l, r)) != mem.end())
    {
        return mem[ii(l, r)];
    }
    else if (l == height+1)
    {
        return mem[ii(l, r)] = prob(h, left - 1, l, r+1);
    }
    else if (r == height+1)
    {
        return mem[ii(l, r)] = prob(h, left - 1, l+1, r);
    }
    else
    {
        return mem[ii(l, r)] = 0.5 * prob(h, left - 1, l+1, r) + 0.5 * prob(h, left-1, l, r+1);
    }
}

int main()
{
    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
        mem.clear();
        double res;

        int N, X, Y;
        scanf("%d %d %d\n", &N, &X, &Y);

        height = 1;
        while ((height + 2) * (height + 3) / 2 <= N) height += 2;
        assert(height * (height + 1) / 2 <= N);
        assert((height + 2) * (height + 3) / 2 > N);

        bool inside = false;
        bool border = false;
        int borderh = -1;
        for (int cury = 0; cury <= height; cury++)
        {
            int cnt = height - cury;
            if (Y == cury && abs(X) <= cnt)
            {
                inside = true;
            }
            else if (cury == Y && abs(X) <= cnt+2)
            {
                border = true;
                borderh = cury;
            }
        }

        if (Y == height + 1 && X == 0)
        {
            border = true;
            borderh = height + 1;
        }

        int numleft = N - height * (height + 1) / 2;

        // printf("Height = %d\n", height);
        // printf("Numleft = %d\n", numleft);
        // printf("Inside = %d\n", inside ? 1 : 0);
        // printf("Border = %d\n", border ? 1 : 0);
        // printf("Borderh = %d\n", borderh);

        if (inside)
        {
            res = 1.0;
        }
        else if (border)
        {
            // printf("AOEEAO\n");
            res = prob(borderh, numleft, 0, 0);
        }
        else
        {
            res = 0.0;
        }

        printf("Case #%d: %lf\n", t+1, res);
    }

    return 0;
}
