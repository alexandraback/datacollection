#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int v[80010];
unsigned long long l, x;

int divi(int r, int a)
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

int mul(int a, int b)
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

int res(int caso)
{
    int i, j, tot=1, p1, p2, p3, d1, d2, q;
    char va[80010];
    scanf("%llu %llu %s", &l, &x, va);
    /*if(caso==70 || caso==73)
    {
        printf("--------Caso: %llu %llu %s\n", l, x, va);
    }*/
    q = 0;
    if(x>4)
        x = (x%4)+4;
    for(i=0;i<x;i++)
    {
        for(j=0;j<l;j++)
        {
            v[q] = va[j]-'i'+2;
            tot = mul(tot, v[q]);
            q++;
        }
    }
    p1 = 1;
    for(d1=0;d1<l*x-2;d1++)
    {
        p1 = mul(p1, v[d1]);
        if(p1==2)
        {
            p2 = 1;
            for(d2=d1+1;d2<l*x-1;d2++)
            {
                p2 = mul(p2, v[d2]);
                p3 = divi(tot, mul(p1, p2));
                if(p1==2 && p2==3 && p3==4)
                    return 1;
            }
        }
    }
    /*v2[0][0] = 1;
    v2[0][1] = tot;
    for(i=1;i<=l;i++)
    {
        v2[i][0] = mul(v2[i-1][0], v[i]);
        v2[i][1] = div(v2[i-1][1], v[i]);
    }
    for(i=0;i<=l;i++)
    {
        if(v[i][0]*t^a==2)
        {
            for(j=0;j<=l;j++)
            {
                if(v[j][1]*t^b==4)
                {
                    if(x%4==(4-((a+b)%4))%4)
                        return 1;
                }
            }
        }
    }*/
    return 0;
}

int main()
{
    int t, i, r;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        r = res(i);
        if(r==0)
            printf("Case #%d: NO\n", i);
        else
            printf("Case #%d: YES\n", i);
    }
}
