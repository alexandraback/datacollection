#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int answers[101];
Int aL=0;

bool Palindrome(Int k)
{
    Int cp=k;
    Int pk=0;

    while(cp>0)
    {
        pk=pk*10+cp%10;
        cp=cp/10;
    }

    if (k==pk)
    return true;
    else
    return false;
}

bool Fair_n_Square(Int k)
{
    if (Palindrome(k))
    {
        if (Palindrome(k*k))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Int i;
    Int n;
    Int l,r,mid;
    Int DOWN,UP;
    Int a,b;

    for (i=1;i<=10000000;i++)
    {
        if (Fair_n_Square(i))
        {
            aL++;
            answers[aL]=i*i;
        }
    }

    scanf("%lld",&n);

    for (i=1;i<=n;i++)
    {
        l=1;
        r=aL;

        DOWN=-1;
        UP=-1;

        scanf("%lld %lld",&a,&b);

        while(l<=r)
        {
            mid=(l+r)/2;

            if (answers[mid]>=a)
            {
                DOWN=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        l=1;
        r=aL;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (answers[mid]<=b)
            {
                UP=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        if (UP==-1 || DOWN==-1)
        {
            printf("Case #%lld: 0\n",i);
        }
        else
        {
            printf("Case #%lld: %lld\n",i,UP-DOWN+1);
        }
    }

    return 0;
}
