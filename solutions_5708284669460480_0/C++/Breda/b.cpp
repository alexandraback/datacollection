#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;
int k, l, s, r, o, ma;
char ori[10];
char ger[10];
char let[10];

void ver()
{
    int i, j, ok;
    int tot = 0;
    for(i=0;i<=s-l;i++)
    {
        ok = 1;
        for(j=0;j<l && ok==1;j++)
        {
            //printf("%d %d ", i, j);
            //printf("%c %c\n", ger[i+j], ori[j]);
            if(ger[i+j]!=ori[j])
                ok=0;
        }
        if(ok==1)
        {
            o++;
            tot++;
        }
    }
    if(tot>ma)
        ma = tot;
}

void rec(int p)
{
    if(p==s)
    {
        //printf("cehgou - %s\n", ger);
        //system("PAUSE");
        r++;
        ver();
        return;
    }
    int i;
    for(i=0;i<k;i++)
    {
        ger[p] = let[i];
        rec(p+1);
    }
}

void resolver(int caso)
{
    r = 0;
    o = 0;
    ma = 0;
    scanf("%d %d %d", &k, &l, &s);
    scanf("%*c%s", let);
    scanf("%*c%s", ori);
    rec(0);
    printf("Case #%d: %.7lf\n", caso, (double)ma-(double)o/(double)r);
}

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
