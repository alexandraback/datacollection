#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m;
int ZIP[11];
bool Flight[11][11];
int path[11];
int best[11];
int curr[11];

int need;
int stak[11];
int sL;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output_small.txt","w",stdout);

    int i;
    int test;
    int a,b;
    bool replace;
    bool firsttime;
    bool good;
    int t;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&n,&m);

        memset(Flight,false,sizeof(Flight));

        for (i=1;i<=n;i++)
        {
            scanf("%d",&ZIP[i]);
        }

        for (i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);

            Flight[a][b]=true;
            Flight[b][a]=true;
        }

        if (n==1)
        {
            printf("Case #%d: %d\n",test,ZIP[1]);
            continue;
        }

        for (i=1;i<=n;i++)
        {
            path[i]=i;
        }

        firsttime=true;

        do
        {
            sL=1;
            stak[1]=1;
            need=2;

            good=false;

            while(sL>0)
            {
                if ( Flight[ path[ stak[sL] ] ][ path[need] ] )
                {
                    sL++;
                    stak[sL]=need;
                    need++;

                    if (need==n+1)
                    {
                        good=true;
                        break;
                    }
                }
                else
                {
                    sL--;
                }
            }

            if ( good )
            {
                for (i=1;i<=n;i++)
                {
                    curr[i]=ZIP[ path[i] ];
                }

                replace=false;

                if (firsttime)
                {
                    replace=true;
                    firsttime=false;
                }
                else
                {
                    for (i=1;i<=n;i++)
                    {
                        if (curr[i]<best[i])
                        {
                            replace=true;
                            break;
                        }
                        else if (curr[i]>best[i])
                        {
                            break;
                        }
                    }
                }

                if (replace)
                {
                    for (i=1;i<=n;i++)
                    {
                        best[i]=curr[i];
                    }
                }
            }
        }while( next_permutation(path+1,path+1+n) );

        printf("Case #%d: ",test);

        for (i=1;i<=n;i++)
        {
            printf("%d",best[i]);
        }
        printf("\n");
    }
}
