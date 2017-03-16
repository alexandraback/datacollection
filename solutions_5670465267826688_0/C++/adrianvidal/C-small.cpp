#include<bits/stdc++.h>
using namespace std;
#define I 2
#define J 3
#define K 4
#define quat int
quat Q[10010];

quat multiply(quat a, quat b){
   if (a==1 || b==1) return a*b;
   if (a==b) return -1;
   
   if (a < 0){
      a*=-1; b*=-1;
   }
   if (b < 0) return (-1)*multiply(a,-b);
   
   if (a > b) return (-1)*multiply(b,a);
   
   if (a == I){
      if (b == J) return K;
      if (b == K) return -J;
   }
   else if (a == J){
      if (b == K) return I;
   }
}

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int L,x; scanf("%d%d",&L,&x);
      string s; cin>>s;
      
      int pos = 0;
      quat all = 1;
      for(int i=0; i<x; i++){
         for(int j=0; j<s.size(); j++,pos++){
            if (s[j] == 'i') Q[pos] = I;
            else if (s[j] == 'j') Q[pos] = J;
            else Q[pos] = K;
            
            all = multiply(all,Q[pos]);
         }
      }
      
      if (all != -1){
         printf("Case #%d: NO\n",cs+1);
         continue;
      }
      
      int n = L*x;
      int left = 0;
      quat c_left = 1;
      for(int i=0; i<n; i++,left++){
         c_left = multiply(c_left,Q[i]);
         if (c_left == I) break;
      }
      
      int right = n-1;
      quat c_right = 1;
      for(int i=n-1; i>=0; i--,right--){
         c_right = multiply(Q[i],c_right);
         if (c_right == K) break;
      }
      
      if (left < n && right >= 0 && left < right){
         printf("Case #%d: YES\n",cs+1);
      }
      else printf("Case #%d: NO\n",cs+1);
   }
}