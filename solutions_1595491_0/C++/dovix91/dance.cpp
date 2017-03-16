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
using namespace std;

int T;
int t[100];

int main() {
   int i, j;
   
   cin>>T;
   for(i=0; i<T; i++) {
      cout<<"Case #"<<i+1<<": ";
   
      int norm=0, spec=0, bad=0, res, n, s, p;
   
      cin>>n>>s>>p;
      for(j=0; j<n; j++) cin>>t[j];
      
      for(j=0; j<n; j++) {
         if(t[j]-p<0) bad++;
         else if(t[j]-p>=2*p-2) norm++;
         else if(t[j]-p>=2*p-4) spec++;
         else bad++;
      }
      
      res = norm;
      res+= spec<s ? spec : s;
      cout<<res<<endl;
   }


   return 0;
}
