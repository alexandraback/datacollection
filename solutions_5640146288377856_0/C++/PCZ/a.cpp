#include <stdio.h>
#include <iostream>
using namespace std;

int t;
int r,c,w;
int ans;

int main()
{
    int tt;
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cin>>r>>c>>w;
        ans=(c/w)*r+w;
        if(c%w==0) ans--;
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
