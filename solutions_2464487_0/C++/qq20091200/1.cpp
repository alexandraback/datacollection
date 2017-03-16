#include <iostream>
#include <cstdio>
#include <cmath>
#define FIN

using namespace std;

typedef long long LL;

LL doit(LL r, LL t) {
    LL first,last,mid;
    first=1;
    last = (LL)sqrt((double)2*t) + 1;
    LL i = t/r + 1;
    LL res=0;
    if(i<last) last = i;
    if(last%2==0) last--;
    last = (last+1)/2;
    while(first<=last) {
        mid=(first+last)>>1;
        LL num = mid*2-1;
        LL sum = (num*num+num)/2+2*r*mid;
       // cout<<mid<<' '<<num<<' '<<sum<<endl;
        if(sum<=t) {
            res=mid;
            first=mid+1;
        }
        else {
            last=mid-1;
        }
    }
    return res;
}

int main()
{
    #ifdef FIN
        freopen("A-small-attempt0.in","r",stdin);
        freopen("A-small-attempt0.out","w",stdout);
    #endif
    int cas,T;
    cin>>T;
    for(cas=1;cas<=T;cas++) {
        LL r,t;
        cin>>r>>t;
        cout<<"Case #"<<cas<<": "<<doit(r,t)<<endl;
    }
    return 0;
}

