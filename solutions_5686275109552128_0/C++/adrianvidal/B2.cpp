#include<bits/stdc++.h>
using namespace std;
int a[1010];

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
      
      map<int,int,greater<int> > H,HH;
      for(int i=0; i<n; i++){
         int x; scanf("%d",&x);
         if (H.find(x) == H.end()) H[x] = 1;
         else H[x]++;
      }
      
      int penalty = 0;
      while(true){
         int maxgain = INT_MIN;
         int half = ((H.begin()->first) + 1)/2;
         int orig = H.begin()->first;
         int sz = 0;
         int opt_sz = -1;
         
         typeof(H.begin()) idx;
         
         for(typeof(H.begin()) it = H.begin(); it!=H.end(); it++){
            typeof(H.begin()) nxt = it; nxt++;
            int nxtval = 0;
            if (nxt != H.end()) nxtval = nxt->first;
            
            sz += it->second;
            int gain = orig - max(nxtval,half) - sz;
            if (gain > maxgain){
               maxgain = gain;
               idx = it;
               opt_sz = sz;
            }
         }
         if (maxgain <= 0) break;
         penalty += opt_sz;
         
         HH.clear();
         for(typeof(H.begin()) it = H.begin(); ; it++){
            int x = it->first;
            if (HH.find(x) == HH.end()) HH[x] = 0;
            HH[x] -= it->second;
            
            int y = (x+1)/2, z = x/2;
            if (HH.find(y) == HH.end()) HH[y] = 0;
            HH[y] += it->second;
            if (HH.find(z) == HH.end()) HH[z] = 0;
            HH[z] += it->second;
            if (it == idx) break;
         }
         
         for(typeof(H.begin()) it = HH.begin(); it != HH.end(); it++){
            int x = it->first;
            if (H.find(x) == H.end()) H[x] = 0;
            H[x] += it->second;
            if (H[x] == 0) H.erase(x);
         }
      }
      printf("Case #%d: %d\n",cs+1,penalty + H.begin()->first);
   }
}