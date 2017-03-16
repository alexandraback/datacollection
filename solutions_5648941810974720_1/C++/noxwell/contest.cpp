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

string d[] = { "ZERO", "EIGHT", "SIX", "SEVEN", "FIVE", "FOUR", "TWO", "ONE", "THREE", "NINE" };
int num[] = { 0, 8, 6, 7, 5, 4, 2, 1, 3, 9 };
char c[] = { 'Z', 'G', 'X', 'S', 'V', 'U', 'W', 'O', 'T', 'I' };
int ctr[26];

string s;
vector<int> ans;

void solve()
{
    cin >> s;
    memset(ctr, 0, sizeof ctr);
    for (int i = 0; i < (int)s.size(); i++)
    {
        ctr[s[i] - 'A']++;
    }
    ans.clear();
    for (int i = 0; i < 10; i++)
    {
        while (ctr[c[i] - 'A'])
        {
            ans.push_back(num[i]);
            for(int j = 0; j < d[i].size(); j++)
                ctr[d[i][j] - 'A']--;
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i];
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