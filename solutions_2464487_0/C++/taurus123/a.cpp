#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
int main()
{
    int T;
    LL r,t;
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
        scanf("%lld%lld",&r,&t);
       /* LL cnt=0;
        while(2*r+1<=t)
        {
            cnt++;
            t-=2*r+1;
            r+=2;
        }*/
        LL left=0;
        LL right=min(LL(999999999+5),t/(2*r+3));
        LL mid,tmp;
        while(left+1<right)
        {
            mid=(left+right)/2;
            tmp=2*mid*mid+(2*r+1+2)*mid+2*r+1-t;
            if(tmp<=0)
                left=mid;
            else
                right=mid;
        }
        mid=right;
        tmp=2*mid*mid+(2*r+1+2)*mid+2*r+1-t;
        if(tmp<=0)
            left=mid;
        printf("Case #%d: %lld\n",cas,left+1);
    }
    return 0;
}
