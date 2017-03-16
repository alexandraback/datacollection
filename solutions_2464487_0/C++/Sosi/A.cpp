#include <stdio.h>
#include <iostream>
using namespace std;

bool func(long long r, long long k,long long t)
{
    if(k == 0) return true;
    return 2LL*k + (2LL*r-1LL) <= t/k;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T; cin>>T;
    for(int tt = 1; tt<= T; tt++)
    {
        long long r, t;
        cin>>r>>t;
        long long lowk = 0LL;
        long long highk = t/(2LL*r-1LL);
        while(highk - lowk > 1)
        {
            long long mid = (highk + lowk)/2LL;
            if(func(r,mid,t)) lowk = mid;
            else highk = mid;
        }
        if(func(r,highk,t)) cout<<"Case #"<<tt<<": "<<highk<<endl;
        else cout<<"Case #"<<tt<<": "<<lowk<<endl;
    }
    return 0;
}
