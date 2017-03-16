#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int T;
int a[100][100];
int n, m;
int nb, nc;

void reset()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = 0;
    a[0][0] = 2;
}

void afis()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            if(a[i][j] == 2)
                printf("c");
            else if(a[i][j])
                printf(".");
            else printf("*");
        printf("\n");
    }
}

void solve()
{
    a[0][1] = a[1][0] = a[1][1] = 1;
    int x, y, c, l;
    x = y = c = l = 2;
    nc -= 4;
    if(nc == 0)
        {afis(); return;}
    if(l < n)
    {
        a[l][0] = a[l][1] = 1;
        nc -= 2;
        l++;
    }
    for(; c < m && nc && nc >= 2; c++, nc-=2)
        a[0][c] = a[1][c] = 1;
    if(nc == 0)
        {afis(); return;}
    for(; l < n && nc && nc >= 2; l++, nc-=2)
        a[l][0] = a[l][1] = 1;
    if(nc == 0)
        {afis(); return;}
    for(x = 2; x < l && nc; x++)
        for(y = 2; y < c && nc; y++)
    {
        a[x][y] = 1;
        nc--;
    }
    if(nc)
        printf("Impossible\n");
    else
        afis();
}

void special()
{
    for(int i = 0; i < n && nc; i++)
        for(int j = 0; j < m && nc; j++)
    {
        if(!a[i][j])
            a[i][j] = 1;
        nc--;
    }
    afis();
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d:\n", i);
        scanf("%d%d%d", &n, &m, &nb);
        nc = n*m - nb;
        reset();
        if(nc == 1)
            afis();
        else if(n == 1 || m == 1)
            special();
        else if(nc == 2 || (nc < 8 && nc%2))
            printf("Impossible\n");
        else
            solve();
    }
    return 0;
}
