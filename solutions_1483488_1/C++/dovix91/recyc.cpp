#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int T;
int a, b;

const int tenpow[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
int curr[10];

int main() {
   int i, j, k, l;
   
   cin>>T;
   for(i=0; i<T; i++) {
      cout<<"Case #"<<i+1<<": ";
      
      int res=0;
      cin>>a>>b;
      
      int dig=1;
      while(b/tenpow[dig-1]>=1) dig++;
      
      for(j=a; j<=b; j++) {
         int temp=j, ok;

     //   cout<<"j: "<<j<<" d: "<<dig<<endl;
         
         for(k=0; k<dig-1; k++) {
            temp = temp/10+(temp%10)*tenpow[dig-2];
            curr[k]=temp;
            ok=1;
            for(l=0; l<k; l++) if(curr[l]==curr[k]) ok=0;
     //      cout<<"   temp: "<<temp;
            if(ok==0) continue;
            if(temp>j && temp<=b) res++;
     //      cout<<" res: "<<res<<endl; 
         }
      
      }

      cout<<res<<endl;
   }

   return 0;
}
