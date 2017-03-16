#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1000000;
const int MAX2 = 7000;
const int BASE = 1000000000;
const int CNT = 100;

int R[MAX];
int B[MAX];

Int f(Int x)
{
    Int res = 0;
    while (x > 0)
    {
        int d = x % 10;
        res = res * 10 + d;
        x /= 10;
    }
    return res;
}

bool OK(Int x)
{
    Int y = x;
    int len = 0;
    while (y > 0)
    {
        ++ len;
        y /= 10;
    }
    if (x % 10 != 1)
        return 0;
    if (f(x) >= x)
        return 0;
    y = x/10;
    int cnt = len/2-1;
    FOR (i,0,cnt)
        if (y % 10 != 0)
            return 0;
        else
            y /= 10;
    return 1;
}

Int Next(Int x)
{
    Int y = x;
    int len = 0;
    while (y > 0)
    {
        ++ len;
        y /= 10;
    }
    if (x % 10 == 0)
        return -1;
    y = x/10;
    int cnt = len/2-1;
    FOR (i,0,cnt)
        y /= 10;
    FOR (i,0,cnt+1)
        y *= 10;
    return y+1;
}

Int solve(Int x)
{
    //cout << x << endl;
    if (x == 1)
        return 1;
    Int n = Next(x);
    if (n == -1 || x < 10)
        return solve(x-1)+1;
    Int res = (x-n);
    Int y = f(n);
    //cout << x << '-' << n << ' ' << y << endl;
    if (y == n)
        res += 1 + solve(y-1);
    else
        res += 1 + solve(y);
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("A-large (3).in", "r", stdin);
    freopen("out.txt", "w", stdout);

    R[0] = 0;
    FOR (i,1,MAX)
        R[i] = INF;
    FOR (i,0,MAX-1)
    {
        if (R[i+1] > R[i]+1)
        {
            B[i+1] = 0;
            R[i+1] = min(R[i+1], R[i] + 1);
        }
        int x = f(i);
        if (x > i && x < MAX && R[x] > R[i]+1)
        {
            B[x] = 1;
            R[x] = min(R[x], R[i] + 1);
        }
    }
    int T;
    cin >> T;
    FOR (test,0,T)
    {
        Int n;
        cin >> n;
        cout << "Case #" << test+1 << ": " << solve(n) << endl;
    }

    //RFOR (i,MAX-1,MAX-100)
       // cout << i << ' ' << R[i] << endl;

  //  FOR (i,1,MAX)
         //cout << i << ' ' << R[i] << ' ' << B[i] << ' ' << solve(i) << endl;



    //FOR (i,1,MAX)
      //  if (R[i] != solve(i))
        //    cout << i << ' ' << R[i] << ' ' << solve(i) << endl;


    /*
    FOR (i,1,100000)
        if (Next(i) != -1 && B[Next(i)] == 0)
         cout << i << ' ' << Next(i) << ' ' << B[Next(i)] << endl;*/

    //FOR (i,0,10000)
       // cout << i << ' ' << Next(i) << endl;

  //  cout << solve(23) << ' ' << R[23] << endl;


    return 0;
}
