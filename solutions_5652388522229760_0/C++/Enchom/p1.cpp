#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

int t;
Int n;

bool seen[10];

void Try(Int k)
{
    while(k>0)
    {
        seen[ k%10LL ]=true;
        k/=10LL;
    }

    return;
}

bool Okay()
{
    int i;

    for (i=0;i<=9;i++)
    {
        if (!seen[i])
        return false;
    }

    return true;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-output.out","w",stdout);

    int i;
    int test;
    Int sum=0;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        memset(seen,false,sizeof(seen));

        scanf("%lld",&n);

        if (n==0)
        {
            printf("Case #%d: INSOMNIA\n",test);
            continue;
        }

        sum=0;
        while(1)
        {
            sum+=n;

            Try(sum);

            if (Okay())
            break;
        }

        printf("Case #%d: %lld\n",test,sum);
    }

    return 0;
}
