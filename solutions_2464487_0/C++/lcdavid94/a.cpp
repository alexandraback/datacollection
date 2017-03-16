#include<iostream>
using namespace std;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a,out","w",stdout);
    long long r,t;
    int T;
    cin>>T;
    for (int TT=1;TT<=T;++TT)
    {
        cin>>r>>t;
        int ans=0;
        while (t>=(r+1)*(r+1)-r*r)
        {
         t-=(r+1)*(r+1)-r*r;
         r+=2;
         ++ans;
        }
        cout<<"Case #"<<TT<<": "<<ans<<endl;
    }
} 
