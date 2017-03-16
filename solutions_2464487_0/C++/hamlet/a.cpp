#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    
    
    int tc;
    cin>>tc;
       
    for(int caso=1;caso<=tc;caso++){
        long long r,t;
        cin>>r>>t;
        
        r++;
        r=r*2-1;
        
        long long lo=1;
        long long hi=1LL<<31;
        
        for(int i=0;i<100;i++){
            long long me=(lo+hi)/2;
            
            if(r> t/me){hi=me;continue;}
            
            if( 2*me*(me-1)<=t-r*me  ){
                lo=me;    
            }else{
                hi=me;    
            }
                
        }
        
        
        cout<<"Case #"<<caso<<": "<<lo<<endl;    
    }   
    
    return 0;
} 
