#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return (a>b);
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(void) {
    freopen("in.txt","rt",stdin);
    freopen("test.txt","wt",stdout);
    int t,tc,r,c,w;
    cin>>t;
    for(tc=1;tc<=t;++tc)
    {
        cin>>r>>c>>w;
        cout<<"Case #"<<tc<<": ";
        int i,ans=0;
        for(i=w;i<c;)
        {
            if(i+w<=c)
            {
                ans++;
                i+=w;
            }
            else
                break;
        }
        if(i<c)
            ans++;
        cout<<ans+w<<"\n";
    }
    return 0;
}
