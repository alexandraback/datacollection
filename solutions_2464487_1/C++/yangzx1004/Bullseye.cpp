#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
__int64 min(__int64 a,__int64 b)
{
    if(a<b) return a;
    return b;
}
int main()
{
    int T,cnt,i,j,k,p,q,m;
    __int64 r,t,tmp,x;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    tmp=(__int64)1000000000*1000000000;
    for(cnt=1;cnt<=T;cnt++)
    {
        scanf("%I64d %I64d",&r,&t);
        q=min(1000000000,tmp/r);
        p=0;
        while(p<q)
        {
            m=(p+q)/2;
            x=(__int64)m*(2*r+2*m-1);
            if(x>t) q=m;
            else p=m+1;
        }
        x=(__int64)p*(2*r+2*p-1);
        while(x>t)
        {
            p--;
            x=(__int64)p*(2*r+2*p-1);
        }
        printf("Case #%d: %d\n",cnt,p);
    }
}
