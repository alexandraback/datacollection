#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int p=0;
    while(t--){
        p++;
        int r,c,w;
        cin>>r>>c>>w;
        int ans=(c/w-1)*r+w;
        if(c%w==0)ans+=(r-1);
        else{
            ans++;
        }
        cout<<"Case #"<<p<<": "<<ans<<"\n";
    }
}
