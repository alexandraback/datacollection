#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI acos(-1.0)

using namespace std;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int cas,t=1;
    long long low,high,ans,tot,r;

    scanf("%d",&cas);
    while(cas--)
    {
        ans=0;
        int cnt=1;
        scanf("%I64d%I64d",&r,&tot);
        while(tot!=0)
        {
            long long num=(2*r+2*cnt-1);
            if(tot>=num&&num>0)
            {
                ans++;
                tot-=num;
            }
            else
               break;
            cnt+=2;
        }
        printf("Case #%d: %I64d\n",t++,ans);
    }
    return 0;
}
