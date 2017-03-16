#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
LL c[10010] =  {1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002} ;
bool hash[10001000];
int cnt[10001000];
LL Sqrt(LL x){
   LL t = max(((LL)sqrt(x*1.0) - 5),0LL);
   while(t*t <= x) t++;
   return t - 1;
}
void Init(){
   for(LL i = 0; i <= 1000; i++){
       hash[c[i]] = true;
   }
   for(int i = 1; i <= 10000000; i++){
       cnt[i] += cnt[i-1] + hash[i];
   }
}
int main(){
        freopen("C-large-1.in","r",stdin);
        freopen("C-large-1.out","w",stdout);
     Init();
     int T,cas = 1;
     cin>>T;
     while(T--){
         LL A,B,ans = 0;
         cin>>A>>B;
         A = Sqrt(A-1);
         B = Sqrt(B);

         printf("Case #%d: %d\n",cas++,cnt[B] - cnt[A]);

     }
    return 0;
}
