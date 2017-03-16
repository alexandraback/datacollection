#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int best1,best2,best3;
char t[2][4], w[2][4];

void wal(int co, int nr)
{
    int a,b,c,d;

    if (co==0)
    {
        if (!t[0][nr])
        {
            wal(1,0);
            return;
        }

        if (t[0][nr]!='?')
        {
            wal(0,nr+1);
            return;
        }

        for (a=0; a<10; a++)
        {
            t[0][nr]='0'+a;
            wal(0,nr+1);
        }

        t[0][nr]='?';
    }
    else
    {
        if (!t[1][nr])
        {
            a=b=0;

            for (c=0; t[0][c]; c++)
                a=10*a+t[0][c]-'0';

            for (c=0; t[1][c]; c++)
                b=10*b+t[1][c]-'0';

            if (abs(a-b)<best1)
            {
                best1=abs(a-b);
                best2=a;
                best3=b;

                for (b=0; t[0][b]; b++)
                {
                    w[0][b]=t[0][b];
                    w[1][b]=t[1][b];
                }

                w[0][b]=w[1][b]=0;

                return;
            }

            if (abs(a-b)==best1)
            {
                if (a<best2)
                {
                    best2=a;
                    best3=b;

                    for (b=0; t[0][b]; b++)
                    {
                        w[0][b]=t[0][b];
                        w[1][b]=t[1][b];
                    }

                    w[0][b]=w[1][b]=0;
                }
                else if (a==best2 && b<best3)
                {
                    best2=a;
                    best3=b;

                    for (b=0; t[0][b]; b++)
                    {
                        w[0][b]=t[0][b];
                        w[1][b]=t[1][b];
                    }

                    w[0][b]=w[1][b]=0;
                }
            }

            return;
        }

        if (t[1][nr]!='?')
        {
            wal(1,nr+1);
            return;
        }

        for (a=0; a<10; a++)
        {
            t[1][nr]='0'+a;
            wal(1,nr+1);
        }

        t[1][nr]='?';
    }
}

int main ()
{
    int a,b,c,d,e,f,g,n,z;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        best1=1000000;
        scanf ("%s %s", t[0], t[1]);
        wal(0,0);
        printf ("Case #%d: %s %s\n", a, w[0], w[1]);
    }

    return 0;
}
