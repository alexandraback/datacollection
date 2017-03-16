#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;  cin>>t;
    for( int tt=1; tt<=t; ++tt ) {
        int r,c,ans,w;
        cin>>r>>c>>w;
        if( c%w==0 ) {
            ans=(c/w)+w-1;
        } else ans = (c/w)+w;
        ans*=r;
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
