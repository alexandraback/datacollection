#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;
#define MAXN 2000

int tcase,n;
vector < pair<int, int >   >sp;
vector < pair<int, int > >tp;

bool IS[MAXN];
bool AS[MAXN];

int main(){
  cin>>tcase;
  for(int tc=1; tc<=tcase; ++tc){
     cin>>n; sp.clear(); tp.clear();
     for(int i=0; i<n; ++i) {
        int x,y; cin>>x>>y; 
        sp.push_back(make_pair(y,x));
     }
     sort(sp.begin(),sp.end());
     for(int i=0; i<n; ++i) {
         tp.push_back(make_pair(sp[i].second,-i));
     }
     sort(tp.begin(),tp.end());
     int mn = 2*n+2;
     do {
       memset(IS,false,sizeof(IS));
       memset(AS,false,sizeof(AS));
       int cv = 0; int idx = 0; 
       for(int i=0; i<n; ++i){
         while(idx<n && cv<sp[i].first){
           if(cv>=tp[idx].first){
         
              int tdx = -tp[idx].second;  
              if(AS[tdx]==false){
                 IS[tdx] = true; 
                 cv += 1;
              }
              ++idx;
           }
           else break;
        }
        if(cv>=sp[i].first){
           if(IS[i]) cv +=1; else cv += 2;  AS[i] = true;
        }
        else break;
       }
       bool gd = true; 
       for(int i=0; i<n; ++i) gd = AS[i];
       if(gd) {
          int ct =0; for(int i=0; i<n; ++i) if(IS[i]) ++ct;
          mn = min(mn,ct+n);
       }
    }while(next_permutation(tp.begin(),tp.end()));
    cout<<"Case #"<<tc<<": "; 
    if(mn==2*n+2) cout<<"Too Bad"<<endl; else cout<<mn<<endl;
  }
  return 0;
}
