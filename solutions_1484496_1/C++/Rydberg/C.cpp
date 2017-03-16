#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <queue>
#include <cassert>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;
typedef long long LL;
#define INF 1000000000
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++) 
#define FS first
#define SD second
#define MP make_pair

LL M[500];
int L[500];

unordered_map<LL, LL> sets;
LL R[50];
int randoms[1000000];
int r_index;
LL sum;

void getRandom() {
  static int a = 7;
  sum = 0;
  FOR(i,0,50) {
    int ind = rand()%500; 
    while (L[ind] == a) {
      ind = rand()%500; 
    }
    L[ind] = a;
    R[i] = M[ind];
    sum += R[i];
  }
  a++;
  if (r_index > 100000 - 100) r_index = rand()%50;
}

set<LL> SS;
int main(){
  int T;scanf("%d",&T);
  srand(123456);
  FORE(test,1,T){
    printf("Case #%d:\n", test);
    int n;scanf("%d",&n);
    SS.clear();

    FOR(i,0,500) scanf("%lld\n", &M[i]);
        FOR(i,0,500) {
    SS.insert(M[i]);
    }
    bool found = false;
    vector<LL> u, v;
    while(!found) {
   //   FOR(i,0,100000) randoms[i] = rand();
      sets.clear();
      r_index = 0;
      FOR(i,0,10000000) {
        getRandom();
        if (found) break;
       // if (i % 1000 == 0) printf("%d\n",i);
        
        
        FOR(i,0,50) {
          if (sets[sum] != 0 && i < 47) {
             LL U = 0;
             FOR(j,i,50) {
               u.push_back(R[j]);
               U += R[j];
             }
             LL S = sum;
             while(S != 0) {
               LL r = sets[S];
               v.push_back(r);
               U -= r;
               if (r == 0) {
                 v.clear();
                 break;
               }
               else {
                 S -= r;
               }
             }
             sort(u.begin(), u.end());
             sort(v.begin(), v.end());
             if (U == 0 && u != v && !v.empty()) {
               found = true;
               break;
             }
             else {
               u.clear();
               v.clear();
             }
          }
          sets[sum] = R[i];
  
          sum -= R[i];
        }
        
      }
    }
    
    FOR(i,0,SZ(u)) {
      printf("%lld ",u[i]);
      if (i > 0 && u[i] == u[i-1]) assert(0);
      if (SS.find(u[i]) == SS.end() ) assert(0);
    }
    printf("\n");
    FOR(i,0,SZ(v)) {
      printf("%lld ",v[i]);
      if (i > 0 && v[i] == v[i-1]) assert(0);
      if (SS.find(v[i]) == SS.end() )  assert(0);
    }
    printf("\n");
  }
}
