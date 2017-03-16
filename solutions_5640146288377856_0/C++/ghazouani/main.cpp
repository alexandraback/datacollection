#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
   freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int jj=1;jj<=t;jj++)
    {
        int c,r,w;
        cin>>r>>c>>w;
        if(w==1) {cout<<"Case #"<<jj<<": "<<r*c<<endl; continue;}
        int x=c/w;
        x+=w;
        if(!(c%w))x--;
        cout<<"Case #"<<jj<<": "<<x<<endl;

    }
    return 0;
}
