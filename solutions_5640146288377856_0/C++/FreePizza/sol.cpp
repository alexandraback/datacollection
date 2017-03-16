#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
freopen("output.txt","w",stdout);
    long int t,i,r,c,w;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>r>>c>>w;
        cout<<"Case #"<<i<<": ";
        if(w==c)
            cout<<w;
        else
            cout<<(ceil((c*1.0)/w)-1+w);
        cout<<"\n";
    }
    return 0;
}
