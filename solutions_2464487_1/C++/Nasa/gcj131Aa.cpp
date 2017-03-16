#include <iostream>
using namespace std;

int main(){
    int u,t;
    
    unsigned long long r,lo,k,hi,L;
    cin>>t;
    for (u=0; u<t; u++){
        cin>>r>>L;
        cout<<"Case #"<<(u+1)<<": ";
        lo=0;
        hi=2000000000;
        while(lo<hi-1){
            k=(lo+hi)/2;
            if (2*r-1+2*k<=L/k) lo=k;
            else hi=k;
        }
        cout<<lo<<endl;
    }
    return 0;
}

