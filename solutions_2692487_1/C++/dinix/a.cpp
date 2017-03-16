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
 for(int tc=1;tc<=ntc;++tc) {
   long long a,n;
   long long moves=0;
   cin>>a>>n;
   cin.get();
   vector<long long> m(n);
   for(long long i=1;i<=n;i++) {
     cin>>m[i-1];
   }
   cin.get();
   sort(m.begin(),m.end());
   if(a==1) { 
     moves=n;
   } else {
     long long mr=n;
     long long ma=n;
     long long tmpa;
     for(long long i=0;i<n;i++) {
       if(a>m[i]) a+=m[i];
       else {
         ma=0;
         tmpa=a;
         while(tmpa<=m[i]) {
           tmpa=2*tmpa-1;
           ++ma;
         }
         mr=n-i;
         if(mr<=ma) {
           moves+=mr;
           break;
         } else {
           moves+=ma;
           a=tmpa+m[i];
         }
         //cout<<moves<<endl;
       } 
     }
   }
   if(moves>n) moves=n; //cout<<"WRONG!  "<<moves<<"  n="<<n<<endl;
   cout<<"Case #"<<tc<<": "<<moves<<endl;
 }
 return 0;
}
