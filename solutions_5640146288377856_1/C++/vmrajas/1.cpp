#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int r,c,w;
        cin>>r>>c>>w;
        int cs1=(c)/w;
        int cs2=(c-1)/w;
        int ans=(r-1)*cs1;
        ans+=cs2;
        ans+=w;
        //ans--;
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
    return 0;
}
