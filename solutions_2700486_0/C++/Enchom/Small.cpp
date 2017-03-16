#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

double totalchance=0.0;
Int limit;
bool wantleft;
Int wantedheight;

void Batrak(Int leftside,Int rightside,Int diamondsleft,double chancetogethere)
{
    if (diamondsleft==0)
    {
        if (wantleft)
        {
            if (leftside>=wantedheight)
            {
                totalchance=totalchance+chancetogethere;
            }
        }
        else
        {
            if (rightside>=wantedheight)
            {
                totalchance=totalchance+chancetogethere;
            }
        }
    }
    else
    {
        if (leftside==limit)
        {
            Batrak(leftside,rightside+1,diamondsleft-1,chancetogethere);
        }
        else if (rightside==limit)
        {
            Batrak(leftside+1,rightside,diamondsleft-1,chancetogethere);
        }
        else
        {
            Batrak(leftside+1,rightside,diamondsleft-1,chancetogethere*0.5);
            Batrak(leftside,rightside+1,diamondsleft-1,chancetogethere*0.5);
        }
    }
}

int main()
{
    Int t;
    Int n,x,y;
    Int i;
    Int coverbought;
    Int diamonds;
    Int cover;

    scanf("%lld",&t);

    for (i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        scanf("%lld %lld",&x,&y);

        totalchance=0.0;
        coverbought=( ABS(x)+ABS(y) )/2 + 1;

        diamonds=1;
        cover=1;

        while(diamonds<n)
        {
            n-=diamonds;
            cover++;
            diamonds+=4;
        }

        if (cover>coverbought)
        {
            printf("Case #%lld: 1.000000\n",i);
            continue;
        }
        else if (cover<coverbought)
        {
            printf("Case #%lld: 0.000000\n",i);
            continue;
        }
        else
        {
            if (n==diamonds)
            {
                printf("Case #%lld: 1.000000\n",i);
                continue;
            }
            if (x==0)
            {
                printf("Case #%lld: 0.000000\n",i);
                continue;
            }

            if (x<0)
            wantleft=true;
            else
            wantleft=false;

            wantedheight=y+1;

            limit=(diamonds-1)/2;
            Batrak(0,0,n,1.0);
        }

        printf("Case #%lld: %.6f\n",i,totalchance);
    }
}
