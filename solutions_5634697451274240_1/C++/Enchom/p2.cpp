#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int t;
char str[211];
int n;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    int test;
    int i;
    int ans=0;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%s",str+1);
        n=strlen(str+1);

        n++;
        str[n]='+';

        ans=0;
        for (i=2;i<=n;i++)
        {
            if (str[i]=='+' && str[i-1]=='-')
            {
                ans+=2;
            }
        }

        if (str[1]=='-')
        ans--;

        printf("Case #%d: %d\n",test,ans);
    }

    return 0;
}
