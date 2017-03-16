#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

#define MAXN 12

int n;
vector<double> a, b;

int ken_move(int naomove, int kenmask)
{
    for (int i = 0; i < n; i++)
        if ((~kenmask & (1 << i)) && b[i] > a[naomove])
            return i;

    for (int i = 0; i < n; i++)
        if (~kenmask & (1 << i))
            return i;

    assert(false);
}

int mem1[1 << MAXN][1 << MAXN];
int mem2[1 << MAXN][1 << MAXN];

int mx1(int nao, int ken)
{
    if (nao == (1 << n) - 1)
        return 0;
    if (mem1[nao][ken] != -1)
        return mem1[nao][ken];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (~nao & (1 << i))
        {
            int kenmove = ken_move(i, ken);
            int cur = mx1(nao | (1 << i), ken | (1 << kenmove));

            if (b[kenmove] < a[i])
                cur++;

            res = max(res, cur);
        }
    }

    return mem1[nao][ken] = res;

    assert(false);
}

int mx2(int nao, int ken)
{
    if (nao == (1 << n) - 1)
        return 0;
    if (mem2[nao][ken] != -1)
        return mem2[nao][ken];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (~nao & (1 << i))
        {
            for (int j = 0; j < n; j++)
            {
                if (~ken & (1 << j))
                {

                    int cur = mx2(nao | (1 << i), ken | (1 << j));
                    if (a[i] > b[j])
                        cur++;

                    res = max(res, cur);
                }
            }
        }
    }

    return mem2[nao][ken] = res;

    assert(false);
}

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        scanf("%d\n", &n);

        a = vector<double>(n);
        b = vector<double>(n);

        for (int i = 0; i < n; i++)
            scanf("%lf", &(a[i]));

        for (int i = 0; i < n; i++)
            scanf("%lf", &(b[i]));

        sort(all(a));
        sort(all(b));

        memset(mem1, -1, sizeof(mem1));
        memset(mem2, -1, sizeof(mem2));

        int y = mx2(0,0);
        int z = mx1(0,0);

        printf("Case #%d: ", t+1);
        printf("%d %d\n", y, z);
    }

    return 0;
}

