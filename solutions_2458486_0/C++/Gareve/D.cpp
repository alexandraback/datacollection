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
#include <map>
#include <set>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;



int key_type[209];
vector<vector<int> > gives;
vector<vector<int> > opens;
vector<int> initial_keys;

typedef pair<vector<int>,int > P;

const int MX = 1 << 20;
map<int,vector<int> > mem;
set<P> st;
int N;


bool get(int mask,int x){
   return (mask & (1<<x)) > 0;
}

set<int> calc_keys(int mask){
   vector<int> keys(201,0);

   foreach(it,initial_keys){
      keys[*it]++;
   }

   for(int i=0;i<N;i++){
      if(get(mask,i)){
         --keys[key_type[i]];
         foreach(it,gives[i]){
            keys[*it]++;
         }
      }
   }
   set<int> ans;
   for(int i=0;i<keys.size();i++)
      if(keys[i] > 0)
         ans.insert(i);
   return ans;
}

void resuelva(){
   int K;scanf("%d %d",&K,&N);
   int x,k,y;
   int mask_target =  (1 << N) - 1;

   initial_keys.clear();
   for(int i=1;i<=K;i++){
      scanf("%d",&k);
      initial_keys.push_back(k);
   }

   gives.clear();gives.resize(N);
   opens.clear();opens.resize(209);
   for(int i=0;i<N;i++){

      scanf("%d",&key_type[i]);
      opens[key_type[i]].push_back(i);

      scanf("%d",&k);
      for(int j=1;j<=k;j++){
         scanf("%d",&x);
         gives[i].push_back(x);
      }
   }

   mem.clear();st.clear();
   mem[0] = vector<int>(0);
   st.insert(P(vector<int>(),0));

   int mask,masky;
   vector<int> now,nowy;
   set<int> keys;
   while(!st.empty()){
      now = st.begin()->first;
      mask = st.begin()->second;
      st.erase(st.begin());

      //printf("mask =  %d\n",mask);

      if(mask == mask_target){
         foreach(it,now){
            printf(" %d",*it);
         }
         printf("\n");
         return;
      }

      keys = calc_keys(mask);
      //printf("keys.size() = %d\n",(int)keys.size());
      foreach(it,keys){k = *it;
         //printf("K = %d\n",k);
         foreach(it2,opens[k]){y = *it2;
            if(get(mask,y) == false){
               //printf("# %d -> %d\n",k,y);
               nowy = now;nowy.push_back(y+1);
               masky = mask | (1<<y);

               map<int,vector<int> >::iterator sit = mem.find(masky);
               if(sit == mem.end()){
                  mem[masky] = nowy;
                  st.insert(P(nowy,masky));
               }else if(sit->second > nowy){
                  sit->second = nowy;
                  st.insert(P(nowy,masky));
               }
            }
         }
      }
   }

   printf(" IMPOSSIBLE\n");
}

int main(){
   int nc;scanf("%d",&nc);   

   for(int i=1;i<=nc;i++){
      printf("Case #%d:",i);
      resuelva();
   }
}
