#include<iostream>
using namespace std;
int a,b,k,t,res;
int main(){
    
    cin>>t;
    for(int q=1;q<=t;q++){
            cin>>a>>b>>k;        
    
            for(int i=0;i<a;i++){
                         for(int j=0;j<b;j++){
                               //  cout<<"i: "<<i<<" j: "<<j<<" i&j: "<<(i&j)<<endl;
                                 if((i&j) < k)res++;        
                     }        
            }
            cout<<"Case #"<<q<<": "<<res<<endl;
            res = 0;
    }
    return 0;
}
