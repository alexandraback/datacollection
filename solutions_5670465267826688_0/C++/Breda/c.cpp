#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int v[10010], l, x;

int conta2(int a, int r)
{
    int i;
    if(a<0)
    {
        a=-a;
        r=-r;
    }
    for(i=1;i<5;i++)
        if(m[a][i]==r)
            return i;
    return 1;
}

int conta(int a, int b)
{
    if(a<0)
    {
        if(b<0)
            return m[-a][-b];
        else
            return -m[-a][b];
    }
    if(b<0)
        return -m[a][-b];
    return m[a][b];
}

int total()
{
    int r = 1;
    int i;
    for(i=0;i<l*x;i++)
    {
        r = conta(r, v[i]);
    }
    return r;
}

int res()
{
    int i, p, j, d1, d2, p1, p2, p3, p3a;
    char va[10010];
    scanf("%d %d %s", &l, &x, va);
    p = 0;
    for(i=0;i<x;i++)
    {
        for(j=0;j<l;j++)
        {
            v[p++] = va[j]-'i'+2;
        }
    }
    p3a = total();
    p1 = 1;
    for(d1=0;d1<l*x-2;d1++)
    {
        p1 = conta(p1, v[d1]);
        p2 = 1;
        for(d2=d1+1;d2<l*x-1;d2++)
        {
            p2 = conta(p2, v[d2]);
            p3 = conta2(conta(p1, p2), p3a);
            if(p1==2 && p2==3 && p3==4)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int t, i, r;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        r = res();
        if(r==0)
            printf("Case #%d: NO\n", i);
        else
            printf("Case #%d: YES\n", i);
    }
}
