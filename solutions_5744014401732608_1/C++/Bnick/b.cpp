#pragma comment (linker, "/STACK:256000000")

#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <complex>
#include <random>

using namespace std;

typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<pii, pii> piiii;

#define pb push_back
#define sq(x) ((x)*(x))
#define tmin(x,y,z) (min(min((x),(y)),(z)))
#define rand32() (((unsigned int)(rand()) << 16) | (unsigned int)(rand()))
#define rand64() (((unsigned int64)(rand32()) << 16) | (unsigned int64)(rand32()))
#define bit(mask, b) ((mask >> b) & 1)
#define biton(mask, bit) (mask | (((uint32)(1)) << bit))
#define bitoff(mask, bit) (mask & (~(((uint32)(1)) << bit)))
#define bitputon(mask, bit) (mask |= (((uint32)(1)) << bit))
#define bitputoff(mask, bit) (mask &= (~(((uint32)(1)) << bit)))
#define FAIL() (*((int*)(0)))++
#define INF ((int)(1e9) + 1337)
#define LINF ((int64)(1e18))
#define EPS 1e-9
#define PI (3.1415926535897932384626433832795)
#define y1 yy1
#define y0 yy0
#define j0 jj0
//#define MOD 1000000007LL
//#define HMOD 1234567913LL
#define HBASE 1009

#define HMOD ((int64)(1e18) + 3LL)
#ifdef _MY_DEBUG
#define HMOD 1000000007
#endif
#define MAX 2000000000
mt19937 ggen;

int b;
int64 m;
int g[100][100];

void solve()
{
    cin >> b >> m;
    for (int i = 1; i <= b; i++)
    {
        for (int j = i + 1; j <= b; j++)
        {
            g[i][j] = 1;
        }
    }
    int64 mx = (1LL << (b - 2));
    if (m > mx)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    else
        cout << "POSSIBLE\n";
    m = mx - m;
    if (m && !(m & 1))
    {
        g[1][b] = 0;
        --m;
    }
    for (int i = 0; i < b - 2; i++)
    {
        if (m & (1 << i))
        {
            g[i + 2][b] = 0;
        }
        m ^= (1 << i);
    }
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
            cout << g[i][j];
        cout << '\n';
    }
}

#define TASK "substr"
int main()
{
    //testgen(200000, 50);
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#else
    //freopen(TASK ".in", "rt", stdin); freopen(TASK ".out", "wt", stdout);
#endif
    //stresstest(); return 0;
    srand(1313);
    ggen = mt19937(13);

    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}