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
   long long B,M;
   cin >> B >> M;
   if( M > (1LL<<(B-2)) ){
      cout << "Case #" << loop+1 << ": " <<"IMPOSSIBLE"<< endl;
      continue;
   }
   cout << "Case #" << loop+1 << ": " <<"POSSIBLE"<< endl;
   for( int i = 0 ; i < B-1; i++ ){
      for( int j = 0 ; j < B-1; j++ ){
         if( i<j ) cout <<"1";
         else cout <<"0";
      }
      if( i==0 && M==(1LL<<(B-2)) ){
         cout <<"1";
         M--;
      }
      else if( i>0 && (M&(1LL<<(i-1)))){
         cout <<"1";
      }
      else{
         cout <<"0";
      }
      cout <<endl;
   }
   for( int i = 0 ; i < B; i++ ){
      cout <<"0";
   }
   cout << endl;
  }
  return 0;
}
