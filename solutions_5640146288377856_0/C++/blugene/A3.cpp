#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int r,c,w;
        cin>>r>>c>>w;
        int ans=r*(c/w)+w;
        if(!(c%w))
        {
            ans--;
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
    return 0;
}
