#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long LL;
int Q;
LL r,t;
LL calc(LL hi)
{
    LL t1=(2*r+1+2*r+hi*4-3),t2=hi;
    if(t1%2==0)t1/=2;else t2/=2;
    if(t/t2<t1)return t+1;
    return t1*t2;
}
int main()
{
    cin>>Q;
    for(int i=1;i<=Q;++i)
    {
        cin>>r>>t;
        printf("Case #%d: ",i);
        LL lo=1,hi=(int)sqrt(t),mid;
        while(lo<hi)
        {
            LL mid=(lo+hi+1)/2;
            if(calc(mid)>t)hi=mid-1;
            else lo=mid;
        }
        cout<<lo<<endl;
    }
    return 0;
}
