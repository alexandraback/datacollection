#include <iostream>
#include <stdio.h>
using namespace std;

int t;

int main()
{
    freopen("D-small.in","r",stdin);
    freopen("D-small.out","w",stdout);

    int K,C,S;
    int test;
    int i;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d %d",&K,&C,&S);

        printf("Case #%d:",test);

        for (i=1;i<=S;i++)
        {
            printf(" %d",i);
        }
        printf("\n");
    }

    return 0;
}
