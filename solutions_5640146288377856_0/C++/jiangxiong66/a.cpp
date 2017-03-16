#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("a.out","w",stdout);
    int t,r,c,w;
    cin>>t;
    for(int cas=1;cas<=t;cas++) {
        cin>>r>>c>>w;
        int ans = w+c/w;
        if(c%w==0) ans--;
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
