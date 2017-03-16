#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D.out","w",stdout);
    int tc;cin>>tc;
    for(int t=1;t<=tc;t++){
        int n,x,y;
        cin>>n>>x>>y;
        int area=x*y;
        cout<<"Case #"<<t<<": ";
        if(area%n||(x<n-1||y<n-1))
            cout<<"RICHARD";
        else
            cout<<"GABRIEL";
            cout<<endl;


    }
}
