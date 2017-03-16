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
#include <set>
#include <map>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;

typedef long long L;
int R,N,M,K;

int LIMIT = 20;
vector<int> sol;
L mult[15];

int give_random(){
   int num = rand();

   num %= (M-1);
   num += 2;

   return num;
}
bool get(int mask,int x){
   return (mask & (1<<x)) > 0;
}
void create_set(){
   sol.clear();
   for(int i=0;i<N;i++){
      sol.push_back(give_random());
   }
   sort(sol.begin(),sol.end());
}
bool guess2(){
   create_set();

   int lim = 1 << N;

   int found = 0;
   vector<bool> v(K,false);

   for(int i=0;i<K;i++){
      if(mult[i] == 1LL and v[i] == false){
         v[i] = true;
         found++;
      }
   }

   for(int mask=1;mask < lim;mask++){
      L mm = 1LL;
      for(int j=0;j<N;j++){
         if(get(mask,j))
            mm *= sol[j];
      }

      for(int i=0;i<K;i++){
         if(mult[i] == mm and v[i] == false){
            v[i] = true;
            found++;
         }
      }
      if(found == K)
         return true;
   }

   return false;
}

void guess(){
   for(int i=0;i<K;i++)
      scanf("%lld",&mult[i]);

   map<vector<int>,int> mp;
   map<vector<int>,int>::iterator it;
   vector<int> best;
   int mx = 0;
   bool gg;

   for(int tryy = 1;tryy <= LIMIT; tryy++){
      gg = guess2();

      if(gg){
         it = mp.find(sol);
         if(it == mp.end()){
            mp[sol] = 1;
            if(1 > mx){
               mx = 1;
               best = sol;
            }
         }else{
            it->second++;
            if(it->second > mx){
               mx = it->second;
               best = sol;
            }
         }
      }
   }
   if(best.empty()){
      create_set();
      best = sol;
   }

   for(int i=0;i<N;i++)
      printf("%d",best[i]);
   printf("\n");
}
void resuelva(){
   scanf("%d %d %d %d",&R,&N,&M,&K);

   
   for(int i=1;i<=R;i++){
      guess();
   }
}

int main(){
   srand(time(NULL));

   int nc;scanf("%d",&nc);
   for(int i=1;i<=nc;i++){
      printf("Case #%d:\n",i);
      resuelva();
   }
}
