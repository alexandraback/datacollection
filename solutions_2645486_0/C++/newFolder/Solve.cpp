#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

const int maxn = 11;
const double eps = 1e-6;

int E, R;
int a[maxn], n;
int d[maxn][maxn];

void update(int &a, int b)
{
    if (a == -1 || a < b)
        a = b;
}

void solved(int cas)
{
    scanf ("%d %d %d", &E, &R, &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    memset(d, -1, sizeof(d));
    d[0][E] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= E; j++)
        {
            if (d[i][j] == -1)
                continue;
            for (int k = 0; k <= j; k++)
                update(d[i+1][min(E, j-k+R)], d[i][j] + k * a[i]);
        }
    }
    int ans = -1;
    for (int i = 0; i <= E; i++)
        if (d[n][i] != -1)
            update(ans, d[n][i]);
    printf ("Case #%d: %d\n", cas, ans);
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf ("%d", &T);
    for (int i = 1; i <= T; i++)
        solved(i);
    return 0;
}