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

int n;
int a[1 << 17];

bool Ok(int ind, double score, double votes)
{
    FOR(i, n)
        if (i != ind)
        {
            double need = max(0.0, score - a[i]);
            votes -= need;
            if (votes < 0)
                return 1;
        }
    return 0;
}

void Solve()
{
    cin >> n;
    FOR(i, n)
        cin >> a[i];
    int x = 0;
    FOR(i, n)
        x += a[i];
    FOR(i, n)
    {
        double L = 0;
        double R = 1;
        while (R - L > 1e-10)
        {
            double m = (L + R) / 2;
            if (Ok(i, a[i] + x * m, x * (1 - m)))
                R = m;
            else
                L = m;
        }
        printf(" %0.9lf" , 100 * (L + R) / 2);
    }
    printf("\n");
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