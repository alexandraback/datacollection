#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,r,c,w,ans;
    cin>>t;
    for(int x=1;x<=t;x++){
        cin>>r>>c>>w;
        ans=r*(c/w);
        if(c%w==0){
            ans+=(w-1);
        }
        else{
            ans+=w;
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
}
