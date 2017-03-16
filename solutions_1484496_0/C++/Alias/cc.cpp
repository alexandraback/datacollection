#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <queue>
#include <memory.h>
#include <iostream>
#include <stack>
#include <complex>
#include <list>

using namespace std;
 
void ASS(bool bb)
{
    if (!bb)
    {
        ++*(int*)0;
    }
}
 
#define FOR(i, x) for (int i = 0; i < (int)(x); i++)
#define CL(x) memset(x, 0, sizeof(x))
#define CLX(x, y) memset(x, y, sizeof(x))
 
#pragma comment(linker, "/STACK:106777216")
 
typedef vector<int> vi;

typedef long long LL;

int a[1 << 17];

int mp[(1 << 17) << 5];

int n;
int m0, m1;

void W(int m)
{
    bool b = 0;
    FOR(i, n)
        if ((m >> i) & 1) {
            if (b)
                cout << " ";
            cout << a[i];
            b = 1;
        }
    cout << endl;
}

void rec(int g, int m, int sum)
{
    if (g == n) {
        if (mp[sum]) {
            m0 = mp[sum];
            m1 = m;
        } else {
            mp[sum] = m;
        }
        return;
    }
    rec(g + 1, m, sum);
    rec(g + 1, m ^ (1 << g), sum + a[g]);
}

void Solve()
{
    cin >> n;
    FOR(i, n)
        cin >> a[i];
    CL(mp);
    rec(0, 0, 0);
    cout << endl;
    W(m0);
    W(m1);
}

int main()
{
    freopen("c:\\gcj\\in.txt", "r", stdin);
    freopen("c:\\gcj\\out.txt", "w", stdout);
    int t;
    cin >> t;
    FOR(i, t)
    {
        printf("Case #%d:", (i + 1));
        Solve();
    }
    return 0;
}