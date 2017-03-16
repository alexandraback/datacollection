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

Int delitels[1000001];

///Disjoint
void Disjoint_n_Add(Int k)
{
    Int i;
    Int cp=k;

    for (i=2;i*i<=cp;i++)
    {
        if (k==1)
        {
            break;
        }
        while (k%i==0)
        {
            delitels[i]++;
            k=k/i;
        }
    }

    if (k>1)
    {
        delitels[k]++;
    }

    return;
}

void Disjoint_n_Sub(Int k)
{
    Int i;
    Int cp=k;

    for (i=2;i*i<=cp;i++)
    {
        if (k==1)
        {
            break;
        }
        while(k%i==0)
        {
            delitels[i]--;
            k=k/i;
        }
    }

    if (k>1)
    {
        delitels[k]--;
    }

    return;
}

void C(Int n,Int k) ///n>=k
{
    Int i;

    for (i=0;i<=n;i++)
    {
        delitels[i]=0;
    }

    if (n==k)
    return;

    for (i=k+1;i<=n;i++)
    {
        Disjoint_n_Add(i);
    }

    for (i=1;i<=n-k;i++)
    {
        Disjoint_n_Sub(i);
    }

    return;
}

double DivideByPowerOf2(Int power,Int n)
{
    Int i;
    double answer=1.0;
    double help;

    for (i=1;i<=n;i++)
    {
        while (delitels[i]>0)
        {
            help=(double)i;
            delitels[i]--;

            while(help>1.0 && power>0)
            {
                help=help/2.0;
                power--;
            }

            answer=answer*help;
        }
    }

    while(power>0)
    {
        answer=answer/2.0;
        power--;
    }

    return answer;
}

int main()
{
    Int t;
    Int n,x,y;
    Int i,j;
    Int coverbought;
    Int diamonds;
    Int cover;
    Int wantedheight;
    Int limit;
    double chance;
    double totalchance;
    double limitchance;

    scanf("%lld",&t);

    for (i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        scanf("%lld %lld",&x,&y);

        coverbought=( ABS(x)+ABS(y) )/2 + 1;
        totalchance=0.0;

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
            if (n==diamonds-1)
            {
                printf("Case #%lld: 1.000000\n",i);
                continue;
            }

            wantedheight=y+1;

            limit=(diamonds-1)/2;

            for (j=wantedheight;j<=limit-1;j++) ///Wanted is less than limit but enough
            {
                if (n-j>=limit || n-j<0) ///other shouldnt be limit nor above limit neither less than zero
                continue;

                C(n,j);
                chance=DivideByPowerOf2(n,n);

                totalchance=totalchance+chance;
            }

            ///Try wanted to be limit
            limitchance=0.0;
            if (n-limit>=0)
            {
                for (j=limit;j<=n;j++) ///i-th is the last one to fall in our side
                {
                    C(j-1,limit-1);
                    chance=DivideByPowerOf2(j,j-1);

                    limitchance=limitchance+chance;
                }
            }

            totalchance=totalchance+limitchance;

            if (n-limit>=wantedheight)
            {
                totalchance=totalchance+limitchance;
            }
        }

        printf("Case #%lld: %.6f\n",i,totalchance);
    }

    return 0;
}
