#include <iostream>

using namespace std;

int t, r, c, w;

int main(){
    cin>>t;
    for(int i=0; i<t; ++i){
        cin>>r>>c>>w;
        int ans=r*(c/w)-1;
        ans+=min(c%w+w,w+1);
        cout<<"Case #"<<i+1<<": "<<ans<<"\n";
    }
}
