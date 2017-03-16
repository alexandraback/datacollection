#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int cas,T;
    long long r,t,left,right,mid,tmp1;
    cin>>T;
    for(cas = 1;cas <= T;++cas) {
        cin>>r>>t;
        left = 1;right = t;
        while(left <= right) {
            mid = (left + right) / 2;
            tmp1 = 2 * mid + 2 * r - 1;
            if(tmp1 <= t / mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        cout<<"Case #"<<cas<<": "<<right<<endl;
    }
}
