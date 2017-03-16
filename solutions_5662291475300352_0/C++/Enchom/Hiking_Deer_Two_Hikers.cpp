#include <iostream>
#include <stdio.h>
using namespace std;
typedef long double Double;

const Double EPS=0.000000001;

struct hiker
{
    int d;
    int m;
    Double spm;
};

int t;
int n;
hiker hikers[1000001];
int L=0;

Double FABS(Double a)
{
    if (a<0.0)
    return -a;
    else
    return a;
}

Double Equal(Double a,Double b)
{
    return FABS(a-b)<EPS;
}

int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-output.txt","w",stdout);

    int i,j;
    int test;
    hiker help;
    Double tim;
    Double dist;
    int d,h,m;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        L=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d %d %d",&d,&h,&m);

            for (j=1;j<=h;j++)
            {
                L++;
                hikers[L].d=d;
                hikers[L].m=m+j-1;
                hikers[L].spm=360.0/(m+j-1);
            }
        }

        if (L==1)
        {
            printf("Case #%d: 0\n",test);
            continue;
        }

        if (hikers[1].d<hikers[2].d)
        {
            help=hikers[1];
            hikers[1]=hikers[2];
            hikers[2]=help;
        }

        if (hikers[1].m==hikers[2].m)
        {
            printf("Case #%d: 0\n",test);
        }
        else if (hikers[1].m<hikers[2].m)
        {
            tim=(Double)(360-hikers[2].d)/hikers[2].spm;
            dist=tim*hikers[1].spm;

            if ( dist>720.0 - (Double)(hikers[1].d) || Equal(dist,720.0 - (Double)(hikers[1].d)) )
            {
                printf("Case #%d: 1\n",test);
            }
            else
            {
                printf("Case #%d: 0\n",test);
            }
        }
        else ///first is slower
        {
            tim=(Double)(360-hikers[1].d)/hikers[1].spm;
            dist=tim*hikers[2].spm;

            if ( dist>720.0 - (Double)(hikers[2].d) || Equal(dist,720.0 - (Double)(hikers[2].d)) )
            {
                printf("Case #%d: 1\n",test);
            }
            else
            {
                printf("Case #%d: 0\n",test);
            }
        }
    }

    return 0;
}
