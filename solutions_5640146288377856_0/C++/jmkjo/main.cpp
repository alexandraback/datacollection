#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tt;
    cin>>tt;
    for(int jj=1;jj<=tt;jj++)
    {
        int c,r,w;
        cin>>r>>c>>w;
        if(w==1) {cout<<"Case #"<<jj<<": "<<r*c<<endl; continue;}
        int y=c/w;
        y+=w;
        if(!(c%w))y--;
        cout<<"Case #"<<jj<<": "<<y<<endl;

    }
    return 0;
}
