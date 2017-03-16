#include<bits/stdc++.h>
using namespace std;
#define I 2
#define J 3
#define K 4

#define ll long long

int mult[][5]={{0, 0,  0,  0,  0},
               {0, 1,  I,  J,  K},
               {0, I, -1,  K, -J},
               {0, J, -K, -1,  I},
               {0, K,  J, -I, -1}};

struct Quaternion{
   int quat;
   Quaternion(){
      quat = 1;
   }
   Quaternion(int q){
      quat = q;
   }
   Quaternion operator*(Quaternion Q){
      if (quat < 0){
         if (Q.quat < 0) return Quaternion(mult[-quat][-Q.quat]);
         return Quaternion(-mult[-quat][Q.quat]);
      }
      if (Q.quat < 0) return Quaternion(-mult[quat][-Q.quat]);
      return Quaternion(mult[quat][Q.quat]);
   }
   Quaternion operator*(int k){
      return (*this)*Quaternion(k);
   }
   bool operator==(int k){
      return quat == k;
   }
};

Quaternion L[10010],R[10010];

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      ll len,rep; scanf("%lld%lld",&len,&rep);
      string s; cin>>s;
      
      Quaternion sect(1);
      for(int i=0; i<s.size(); i++){
         if (s[i] == 'i') L[i] = Quaternion(I);
         else if (s[i] == 'j') L[i] = Quaternion(J);
         else if (s[i] == 'k') L[i] = Quaternion(K);
         else continue;
         R[i] = L[i];
         sect = sect * L[i];
      }
      
      for(int i=1; i<s.size(); i++) L[i] = L[i-1]*L[i];
      for(int i = (int)s.size()-2; i>=0; i--) R[i] = R[i]*R[i+1];
      
      Quaternion pw[4];
      pw[0] = Quaternion(1);
      for(int i=1; i<4; i++) pw[i] = pw[i-1] * sect;
      
      if (pw[rep%4].quat != -1){
         printf("Case #%d: NO\n",cs+1);
         continue;
      }
      
      ll minleft = LONG_LONG_MAX;
      for(int i=0; i+1<s.size(); i++){
         for(int j=0; j<4; j++){
            if (pw[j]*L[i] == I){
               minleft = min(minleft,j*len + i+1);
            }
         }
      }
      
      ll minright = LONG_LONG_MAX;
      for(int i=(int)s.size()-1; i>=0; i--){
         for(int j=0; j<4; j++){
            if (R[i]*pw[j] == K){
               minright = min(minright,j*len + (int)s.size() - i);
            }
         }
      }
      
      if (minleft == LONG_LONG_MAX || minright == LONG_LONG_MAX){
         printf("Case #%d: NO\n",cs+1);
         continue;
      }
      
      if (minleft + minright < len*rep){
         printf("Case #%d: YES\n",cs+1);
      }
      else printf("Case #%d: NO\n",cs+1);
   }
}