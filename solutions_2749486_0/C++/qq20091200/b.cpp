#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

#define readFile

using namespace std;

const int MAX = 1000010;

typedef long long LL;

int x,y;

void doit()
{
    int i;
    if(x<0)
    {
        x*=-1;
        for(i=0;i<x;i++)
        printf("EW");
    }
    else if(x>0)
    {
        for(i=0;i<x;i++)
        printf("WE");
    }

    if(y<0)
    {
        y*=-1;
        for(i=0;i<y;i++)
        printf("NS");
    }
    else if(y>0)
    {
        for(i=0;i<y;i++)
        printf("SN");
    }

    puts("");
}

int main()
{
    #ifdef readFile
        freopen("B-small-attempt0.in","r",stdin);
        freopen("B-small-attempt0.out", "w", stdout);
    #endif
    int T,cas;
    scanf("%d",&T);
    for(cas = 1;cas <= T;cas++)
    {
        scanf("%d%d", &x, &y);
        printf("Case #%d: ",cas);
        doit();
    }
    return 0;
}
