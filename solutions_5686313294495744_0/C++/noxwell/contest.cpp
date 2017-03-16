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

int n, m;
unordered_map<string, int> mp1, mp2;
pii a[1010];
bool u1[16], u2[16];

void solve()
{
    mp1.clear();
    mp2.clear();
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (!mp1.count(s1))
        {
            int sz = mp1.size();
            mp1[s1] = sz;
        }
        if (!mp2.count(s2))
        {
            int sz = mp2.size();
            mp2[s2] = sz;
        }
        a[i].first = mp1[s1];
        a[i].second = mp2[s2];
    }
    int ans = 0;
    for (int i = 0; i < (1 << m); i++)
    {
        memset(u1, 0, sizeof u1);
        memset(u2, 0, sizeof u2);
        int ti = i;
        int ctr = 0;
        for (int j = 0; j < m; j++)
        {
            if (ti & 1)
            {
                u1[a[j].first] = 1;
                u2[a[j].second] = 1;
            }
            else
                ctr++;
            ti >>= 1;
        }
        ti = i;
        bool fail = false;
        for (int j = 0; j < m && !fail; j++)
        {
            if (!(ti & 1) && (!u1[a[j].first] || !u2[a[j].second]))
                fail = true;
            ti >>= 1;
        }
        if (!fail)
            ans = max(ans, ctr);
    }
    cout << ans;
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