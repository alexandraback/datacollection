#include<iostream>
#include<algorithm>
#include<cstdio>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
typedef long long LL;
const int mn=10000000;
LL f[mn],A,B;
int i,tt,Q,T,d[20];
bool check(LL v)
{
    int l=0,i;
    for(;v!=0;v/=10)d[++l]=v%10;
    fo(i,1,l)
        if(d[i]!=d[l-i+1])return 0;
    return 1;
}
int main()
{
    fo(i,1,10000000)
    {
        if(!check(i))continue;
        LL now=(LL)i*i;
        if(check(now))
            f[++tt]=now;
    }
    cin>>Q;
    fo(T,1,Q)
    {
        cin>>A>>B;
        int y=upper_bound(f+1,f+1+tt,B)-f-1;
        int x=upper_bound(f+1,f+1+tt,A-1)-f-1;
        printf("Case #%d: %d\n",T,y-x);
    }
    return 0;
}
