#include <iostream>
using namespace std;
int main(){
    int T,C,S;
    cin>>T;
    for(C=1;C<=T;++C){
        int ans=0;
        int cn=0;
        cin>>S;
        char p;
        for(int i=0;i<=S;++i){
            cin>>p;
            if(cn<i){
                ans+=i-cn;
                cn=i;
            }
            cn+=p-'0';
        }
        cout<<"Case #"<<C<<": "<<ans<<endl;
    }
    return 0;
}
