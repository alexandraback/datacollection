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
        int ans=(c/w)*(r-1);
        if(c%w==0){
            ans+=(c/w+w-1);
        }else{
            ans+=(c/w+w);
        }
        cout<<"Case #"<<p<<": "<<ans<<"\n";
    }
}
