#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int komb[27][3],b,k,j,p,s;
int t[27];

bool wal(int nr, int ilu)
{
    if (nr==b)
    {
        if (ilu)
            return false;

        int x,y,z,v,r;

        for (x=0; x<j; x++)
            for (y=0; y<p; y++)
                for (z=0; z<s; z++)
                {
                    v=0;

                    for (r=0; r<b; r++)
                        if (t[r] && komb[r][0]==x && komb[r][1]==y)
                            v++;

                    if (v>k)
                        return false;
                }

        for (x=0; x<j; x++)
            for (y=0; y<p; y++)
                for (z=0; z<s; z++)
                {
                    v=0;

                    for (r=0; r<b; r++)
                        if (t[r] && komb[r][0]==x && komb[r][2]==z)
                            v++;

                    if (v>k)
                        return false;
                }

        for (x=0; x<j; x++)
            for (y=0; y<p; y++)
                for (z=0; z<s; z++)
                {
                    v=0;

                    for (r=0; r<b; r++)
                        if (t[r] && komb[r][2]==z && komb[r][1]==y)
                            v++;

                    if (v>k)
                        return false;
                }

        return true;
    }

    if (ilu)
    {
        t[nr]=1;

        if (wal(nr+1,ilu-1))
        {
            t[nr]=0;
            return true;
        }
    }

    t[nr]=0;
    return wal(nr+1,ilu);
}

bool wal2(int nr, int ilu)
{
    if (nr==b)
    {
        if (ilu)
            return false;

        int x,y,z,v,r;

        for (x=0; x<j; x++)
            for (y=0; y<p; y++)
                for (z=0; z<s; z++)
                {
                    v=0;

                    for (r=0; r<b; r++)
                        if (t[r] && komb[r][0]==x && komb[r][1]==y)
                            v++;

                    if (v>k)
                        return false;
                }

        for (x=0; x<j; x++)
            for (y=0; y<p; y++)
                for (z=0; z<s; z++)
                {
                    v=0;

                    for (r=0; r<b; r++)
                        if (t[r] && komb[r][0]==x && komb[r][2]==z)
                            v++;

                    if (v>k)
                        return false;
                }

        for (x=0; x<j; x++)
            for (y=0; y<p; y++)
                for (z=0; z<s; z++)
                {
                    v=0;

                    for (r=0; r<b; r++)
                        if (t[r] && komb[r][2]==z && komb[r][1]==y)
                            v++;

                    if (v>k)
                        return false;
                }

        for (r=0; r<b; r++)
            if (t[r])
                printf ("%d %d %d\n", komb[r][0]+1, komb[r][1]+1, komb[r][2]+1);

        return true;
    }

    if (ilu)
    {
        t[nr]=1;

        if (wal2(nr+1,ilu-1))
        {
            t[nr]=0;
            return true;
        }
    }

    t[nr]=0;
    return wal2(nr+1,ilu);
}

int main ()
{
    int a,c,d,e,f,g,z;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        scanf ("%d%d%d%d", &j, &p, &s, &k);
        b=0;

        for (c=0;c<j;c++)
            for (d=0;d<p;d++)
                for (e=0;e<s;e++)
                {
                    komb[b][0]=c;
                    komb[b][1]=d;
                    komb[b++][2]=e;
                }

        for (c=b; 1; c--)
            if (wal(0,c))
            {
                printf ("Case #%d: %d\n", a,c);
                wal2(0,c);
                break;
            }
    }

    return 0;
}
