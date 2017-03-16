#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define ll long long
using namespace std;
ll a[39]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("dd.txt","w+",stdout);
    int ncase,time=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        printf("Case #%d: ",++time);
        ll l,r;
        scanf("%I64d%I64d",&l,&r);
        int i,ans=0;
        for(i=0;i<39;i++)
        {
            if(a[i]*a[i]<=r)
            ans++;
            else
            break;
        }
        for(i=0;i<39;i++)
        {
            if(a[i]*a[i]<=l-1)
            ans--;
            else
            break;
        }
        printf("%d\n",ans);

    }
    return 0;
}
