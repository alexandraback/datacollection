#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

bool czy[31];
int t[5],tmp[5],d,v;

bool probuj (int mam, int dok)
{
    int x,y;

    if (mam==dok)
    {
        for (x=1; x<=v; x++)
            czy[x]=0;

        for (y=0; y<d; y++)
            for (x=v-t[y]; x>=0; x--)
                if (czy[x])
                    czy[x+t[y]]=1;

        for (y=0; y<mam; y++)
            for (x=v-tmp[y]; x>=0; x--)
                if (czy[x])
                    czy[x+tmp[y]]=1;

        for (y=1; y<=v && czy[y]; y++);

        return (y>v);
    }

    for (x=1; x<=v; x++)
    {
        for (y=0; y<d; y++)
            if (x==t[y])
                break;

        if (y<d)
            continue;

        for (y=0; y<mam; y++)
            if (x==tmp[y])
                break;

        if (y<mam)
            continue;

        tmp[mam]=x;

        if (probuj(mam+1,dok))
            return 1;
    }

    return 0;
}

int main ()
{
    int a,b,c,e,f,g,n,z;

    scanf ("%d", &z);
    czy[0]=1;

    for (a=1; a<=z; a++)
    {
        scanf ("%d%d%d", &d, &d, &v);

        for (b=0; b<d; b++)
            scanf ("%d", &t[b]);

        for (b=0; b<=5; b++)
            if (probuj(0,b))
                break;

        printf ("Case #%d: %d\n", a, b);
    }

    return 0;
}
