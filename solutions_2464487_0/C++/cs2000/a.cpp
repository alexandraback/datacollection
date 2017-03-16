#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;  
struct swing{
	int p,x;
    bool operator<(const swing ext) const{
    return (p<ext.p);
    }
};
int main(){
    int tt,z;
    long long ans,r,t,n,x,f,a,b,c;
    cin>>tt;
    for (z=1; z<=tt; ++z){
        cin>>r>>t;
        
        f=2*r+1;
       // cout<<r<<" "<<f<<" "<<t<<endl;
        a=1;
        b=1;
        for (int i=1; i<=9; ++i)
            b=b*10;
        b=b+1;
        b=min(b,t/(f-2)+1);
        while (a<b-1){
              c=(a+b) / 2;
              if (c==a)
                 c=a+1;
              if (2*c*c==t-(f-2)*c){
                 a=c;
                 break;
              }
              else if (2*c*c<t-(f-2)*c){
                     a=c;
              }
              else{
                   b=c;
              }
            // cout<<a<<" "<<b<<" "<<c<<" "<<t<<endl;
        }
        cout<<"Case #"<<z<<": "<<a<<endl;
    }
    return 0;
}
