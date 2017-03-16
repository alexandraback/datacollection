#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
 int ntc;
 cin>>ntc;
 cout.precision(7);
 cout.setf( std::ios::fixed, std:: ios::floatfield );
 vector<long long> maxonlev(101);
 maxonlev[0]=0;
 maxonlev[1]=1;
 for(long long i=2;i<=100;++i) {
   maxonlev[i]=2*maxonlev[i-1]+3;
 }
 vector<long long> fac(101);
 fac[0]=1;
 fac[1]=1;
 for(long long i=2;i<=100;++i) {
   fac[i]=fac[i-1]*i;
 }
 for(int tc=1;tc<=ntc;++tc) {
   long long n,myx,myy;
   cin>>n>>myx>>myy;
   if(myx<0) myx=-myx;
   long long reachx;
   long long l=1;
   long long mmaxlev=0;
   while(n>maxonlev[l]+mmaxlev) { ++l; mmaxlev+=maxonlev[l-1]; }
   if(n<maxonlev[l]+mmaxlev) { --l; mmaxlev-=maxonlev[l]; }
   long long free=n-maxonlev[l]-mmaxlev;
   reachx=2*(l-1);
   double p;
   //cout<<"lev: "<<l<<" max: "<<maxonlev[l]<<" free: "<<free<<" reach: "<<reachx<<endl;
   if(myx+myy<=reachx) {
     p=1.0;
   } else if(myx+myy>reachx && free==0) {
     p=0.0;
   } else if(myx==0) {
     p=0.0;
   } else if(myx+myy-reachx==2 && free>0) {
     //if(free>maxonlev[l+1]/2) { p=1.0; }
     //else 
     if(free<myy) {
       p=0.0;
     } else {
       //p=1.0-1.0/(1<<free)-myy*1.0/(1<<free); 
       //p=(fac[free]*1.0)/(fac[myy+1]*fac[free-myy-1])*1.0/(1<<(free));
       p=1.0-1.0/(1<<free);
       for(long long i=0;i<myy;++i) {
         p-=(fac[free]*1.0)/(fac[i+1]*fac[free-i-1])*1.0/(1<<(free));
       }
     }
   } else {
     p=0.0;
   }
   cout<<"Case #"<<tc<<": "<<p<<endl;
 }
 return 0;
}
