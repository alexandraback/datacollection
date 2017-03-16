#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
   int N;
   cin >> N;
   vector< pair<string,string> > dict;
   for( int i = 0 ; i < N; i++){
      pair<string,string> p;
      cin >> p.first >> p.second;
      dict.push_back(p);
   }
   int ans = 0;
   for( int mask = 0 ; mask < (1<<N); mask++ ){
      set<string> s1;
      set<string> s2;
      for( int i = 0 ; i <N; i++ ){
         if( mask&(1<<i) ){
            s1.insert(dict[i].first);
            s2.insert(dict[i].second);
         }
      }
      bool ok = true;
      int tmp=0;
      for( int i = 0 ; i <N ; i++){
         if( (mask&(1<<i))==0 ){
            tmp++;
            if( s1.find(dict[i].first)==s1.end() ){
               ok=false;
               break;
            }
            if( s2.find(dict[i].second)==s2.end() ){
               ok=false;
               break;
            }
         }
      }
      if( ok ){
         ans=max(tmp,ans);
      }
   }
   cout << "Case #" << loop+1 << ": " <<ans<< endl;
  }
  return 0;
}
