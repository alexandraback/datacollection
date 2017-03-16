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
const int MAX = 2000000;
const int MAX2 = 7000;
const int BASE = 1000000000;
const int CNT = 100;

int R[MAX];

int f(int x)
{
    int res = 0;
    while (x > 0)
    {
        int d = x % 10;
        res = res * 10 + d;
        x /= 10;
    }
    return res;
}

int solve(Int x)
{
    if (x == 1)
        return 1;
    int y = f(x);
    if (y < x-1 && (x % 10 != 0))
        return solve(y)+1;
    else
        return solve(x-1)+1;
}

int main()
{
    freopen("A-small-attempt0 (4).in", "r", stdin);
    freopen("out.txt", "w", stdout);

    R[0] = 0;
    FOR (i,1,MAX)
        R[i] = INF;
    FOR (i,0,MAX-1)
    {
        R[i+1] = min(R[i+1], R[i] + 1);
        int x = f(i);
        if (x > i && x < MAX)
            R[x] = min(R[x], R[i] + 1);
    }
    int T;
    cin >> T;
    FOR (test,0,T)
    {
        int n;
        cin >> n;
        cout << "Case #" << test+1 << ": " << R[n] << endl;
    }

    /*
    FOR (i,1,100)
        cout << i << ' ' << R[i] << ' ' << solve(i) << endl;*/







    return 0;
}
