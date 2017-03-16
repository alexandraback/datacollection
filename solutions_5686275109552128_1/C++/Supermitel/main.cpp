#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int a[1010], n, t;
int minim, add;


void citire()
{
    int m;
    scanf("%d", &m);
    int x;

    for(int i = 0; i < 1005; i++)
        a[i] = 0;
    n = 0;
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        a[x]++;
        n = max(n, x);
    }
    minim = n;
}

void solve()
{
    for(int i = 1; i < n; i++)
    {
        int sum = 0;
        for(int j = 2; j <= n; j++)
            sum += a[j] * (j/i + (j%i?1:0) - 1);
        if(sum + i < minim) minim = sum + i;
    }
}

int main()
{
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);

    scanf("%d", &t);
    for(int q = 1; q <= t; q++)
    {
        citire();
        solve();
        printf("Case #%d: %d\n", q, minim);
    }
    return 0;
}
