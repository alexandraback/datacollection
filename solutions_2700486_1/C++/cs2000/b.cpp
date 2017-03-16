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
long double ncr[1000],p[2000];
void formncr(long n){
     int i,j,k;
     memset(ncr,1,sizeof ncr);
     for (i=0; i<=n; ++i){
         long double a=1;
         for (j=1; j<=i; ++j){
             a=a*(n-j+1) / (i-j+1) / 2; 
         }
         for (j=i+1; j<=n; ++j)
             a=a/2;
         ncr[i]=a;
     }
}
int main(){
            cout.setf(ios::fixed,ios::floatfield);
        cout.precision(6);
    long long e,s,x,y,n,l,tar,size,rm;
    long double ans;
    int z,i,j,k,t;
    long long lvl[1000];
    e=1;
    j=0;
    s=0;
    while (s<1000000){
          s+=e;
          lvl[j]=s;
          e+=4;
          j++;
    }
    cin>>t;
    for (z=1; z<=t; ++z){
        cin>>n>>x>>y;
        l=(abs(x)+abs(y))/2;
        for (i=0; i<1000; ++i){
            if (n<=lvl[i]){
               tar=i;
               break;
            }
        }
       // cout<<tar<<" "<<l<<" "<<lvl[l]<<endl;
        if (tar>l)
           ans=1;
        else if (tar<l)
             ans=0;
        else if (n==lvl[l])
             ans=1;
        else{
             size=lvl[l]-lvl[l-1];
             rm=n-lvl[l-1];
             if (y==2*l)
                ans=0;
             else if (y>rm)
                  ans=0;
             else{
                  memset(p,0,sizeof p);
                  formncr(rm);
                  for (i=0; i<=rm; ++i){
                  //    cout<<i<<" "<<ncr[i]<<endl;
                      if (i>2*l)
                         p[2*l]+=ncr[i];
                      else if (rm-i>2*l)
                         p[rm-2*l]+=ncr[i];
                      else
                          p[i]+=ncr[i];
                  }     
                  ans=1;
                  for (i=2*l; i>=0; --i){
                      if (rm-i<=y)
                         ans-=p[i];
                  }
             }
        } //end if big if
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
    return 0;
}
