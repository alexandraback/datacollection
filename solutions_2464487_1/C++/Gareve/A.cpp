/**
* @author Gareve
*/
#define DEBUG
#ifndef NDEBUG 
   #define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
   #define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;

typedef long long L;

L sm(L N){
   return (N * (N + 1LL)) / 2LL;
}

L f(L r,L N){
   L sum = 0LL;

   L ii;
   if(r % 2LL == 1LL){//start with pair
      sum = -N;
      ii = (r + 1LL) / 2LL;
   }else{
      sum = N;
      ii = (r) / 2LL;
   }
   /*
   DBG(ii);
   DBG(sum);
   DBG(sm(ii + N - 1LL));
   DBG(sm(ii - 1LL));
   */
   sum += 4LL*sm(ii + N - 1LL) - sm(ii-1LL);
   assert(sum >= 0LL);

   return sum;
}

//2x10^18
void resuelva(){
   L r,t;scanf("%lld %lld",&r,&t);

   //printf(">> %lld\n",f(r,1));return;

   L a = 1,b = 1LL,m;

   while(f(r,b) <= t){
      b <<= 1LL;
   }

   assert(f(r,b) > t);
   while(a + 1LL < b){
      m = (a + b) / 2LL;
      if(f(r,m) <= t){
         a = m;
      }else{
         b = m;
      }
   }
   printf("%lld\n",a);
}

int main(){
   int nc;scanf("%d",&nc);
   for(int i=1;i<=nc;i++){
      printf("Case #%d: ",i);
      resuelva();
   }
}
