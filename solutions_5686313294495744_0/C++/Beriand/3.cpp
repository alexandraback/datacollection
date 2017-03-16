#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
using namespace std;

string t[16][2];
bool mam[16];
int n,fake;

bool wal (int nr, int gut)
{
    int a,b,c,d;

    if (nr==n)
    {
        d=0;

        for (a=0; a<n; a++)
            if (!mam[a])
            {
                for (b=0; b<n; b++)
                    if (mam[b] && t[b][0]==t[a][0])
                        break;

                for (c=0; c<n; c++)
                    if (mam[c] && t[c][1]==t[a][1])
                        break;

                if (b<n && c<n)
                    d++;
            }

        if (d==fake)
            return true;

        return false;
    }

    if (gut==0)
        return wal(nr+1,0);

    mam[nr]=1;

    if (wal(nr+1,gut-1))
        return true;

    mam[nr]=0;

    if (wal(nr+1,gut))
        return true;

    return false;
}

int main ()
{
    int a,b,c,d,e,f,g,z;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        scanf ("%d", &n);

        for (b=0; b<n; b++)
            cin>>t[b][0]>>t[b][1];

        for (b=min(12,n-2); b; b--)
        {
            fake=b;

            if (wal(0,n-b))
                break;
        }

        printf ("Case #%d: %d\n", a, b);
    }

    return 0;
}
