#include <iostream>
#include <cstdio>
#include <map>
#include <math.h>
#include <string.h>
using namespace std;

__int64 r,t;

__int64 judge(__int64 k)
{
    return k*2*r-3*k+2*k*(k+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%I64d%I64d",&r,&t);
        __int64 head=0,tail=t/2/r,mid;
        tail=min(tail,(__int64)sqrt(t/2));
        //cout<<head<<" "<<tail<<endl;
        while(head<tail)
        {
            mid=(head+tail+1LL)>>1;
            if(judge(mid)<=t) head=mid;
            else tail=mid-1;
        }
        printf("Case #%d: %I64d\n",cas,head);
        //cout<<head<<endl;
    }
    return 0;
}
