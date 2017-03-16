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
#define MOD 1000000007LL
#define HMOD 1234567913LL
#define HBASE 1009

//#define HMOD ((int64)(1e18) + 3LL)
//#ifdef _MY_DEBUG
//#define HMOD 1000000007
//#endii
#define MAX 2000000000
mt19937 ggen;

struct trip
{
    int64 dt, a, b;
    trip() {}
    trip(int64 a, int64 b) : a(a), b(b)
    {
        dt = abs(a - b);
    }
};

bool operator<(const trip &a, const trip &b)
{
    if (a.dt < b.dt)
        return 1;
    else if (a.dt == b.dt && a.a < b.a)
        return 1;
    else if (a.dt == b.dt && a.a == b.a && a.b < b.b)
        return 1;
    else
        return 0;
}

int n;
string a, b;
int64 pw[18];

void init()
{
    pw[0] = 1;
    for (int i = 1; i < 18; i++)
        pw[i] = pw[i - 1] * 10;
}

inline trip get(bool le)
{
    trip res(0, 0);
    for (int i = 0; i < n; i++)
    {
        if(a[n - 1 - i] != '?')
            res.a += pw[i] * (int64)(a[n - 1 - i] - '0');
        if (b[n - 1 - i] != '?')
            res.b += pw[i] * (int64)(b[n - 1 - i] - '0');
        if (a[n - 1 - i] == '?' && le)
            res.a += pw[i] * 9;
        if (b[n - 1 - i] == '?' && !le)
            res.b += pw[i] * 9;
    }
    res.dt = abs(res.a - res.b);
    return res;
}

void solve()
{
    cin >> a >> b;
    n = a.size();
    bool end = false;
    trip ans(0, 2e18);
    for (int i = 0; i < n && !end; i++)
    {
        if (a[i] == '?' && b[i] == '?')
        {
            trip t;
            a[i] = '0';
            b[i] = '1';
            t = get(1);
            ans = min(ans, t);
            a[i] = '1';
            b[i] = '0';
            t = get(0);
            ans = min(ans, t);
            a[i] = '0';
            b[i] = '0';
        }
        else if (a[i] == '?' && b[i] != '?')
        {
            trip t;
            if (b[i] != '0')
            {
                a[i] = b[i] - 1;
                t = get(1);
                ans = min(ans, t);
            }
            if (b[i] != '9')
            {
                a[i] = b[i] + 1;
                t = get(0);
                ans = min(ans, t);
            }
            a[i] = b[i];
        }
        else if (a[i] != '?' && b[i] == '?')
        {
            trip t;
            if (a[i] != '0')
            {
                b[i] = a[i] - 1;
                t = get(0);
                ans = min(ans, t);
            }
            if (a[i] != '9')
            {
                b[i] = a[i] + 1;
                t = get(1);
                ans = min(ans, t);
            }
            b[i] = a[i];
        }
        else
        {
            trip t;
            if (a[i] != b[i])
                end = true;
            t = get(a[i] <= b[i]);
            ans = min(ans, t);
        }
    }
    if (!end)
    {
        auto t = get(1);
        ans = min(ans, t);
    }
    cout << setw(n) << setfill('0') << ans.a << ' ' << setw(n) << setfill('0') << ans.b;
}

//void testgen(int n)
//{
//    ofstream ofs("input.txt", ios_base::out | ios_base::trunc);
//    mt19937 gen(1337);
//    uniform_int_distribution<int> dist('a', 'z');
//    for (int i = 0; i < n; i++)
//        ofs << (char)dist(gen);
//    ofs.close();
//}

#define TASK "substr"
int main()
{
    //stresstest(50, 100, 70); return 0;
    //testgen(20000); return 0;
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#else
    //freopen(TASK ".in", "rt", stdin); freopen(TASK ".out", "wt", stdout);
#endif
    //stresstest(); return 0;
    srand(1313);
    ggen = mt19937(13);

    init();
    int ts;
    cin >> ts;
    for (int i = 0; i < ts; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}