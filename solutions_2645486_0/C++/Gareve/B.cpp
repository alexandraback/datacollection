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
#include <queue>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;

typedef long long L;
typedef pair<int,int> P;


L mem[11][6];
L vc[11];

L E,R,N;


void resuelva(){
   scanf("%lld %lld %lld",&E,&R,&N);
   memset(mem,-1,sizeof(mem));

   for(int i=1;i<=N;i++)
      scanf("%lld",&vc[i]);

   L ans = 0;

   queue<P> q;
   q.push(P(0,E));
   mem[0][E] = 0;


   int x,e,ee;
   L v,vv;
   while(!q.empty()){
      x = q.front().first;
      e = q.front().second;
      q.pop();

      if(x == N){
         ans = max(ans,mem[x][e]);
         continue;
      }
      v = mem[x][e];

      x++;
      for(int i=0;i<=E;i++){//Spend
         ee = e - i;
         if(ee < 0)continue;
         ee += R;
         if(ee > E)
            ee = E;

         vv = v + i * vc[x];

         if(mem[x][ee] == -1LL){
            q.push(P(x,ee));
         }

         mem[x][ee] = max(mem[x][ee],vv);
      }
   }

   printf("%lld\n",ans);
}

int main(){
   int nc;scanf("%d",&nc);
   for(int i=1;i<=nc;i++){
      printf("Case #%d: ",i);
      resuelva();
   }
}
