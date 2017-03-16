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
int bitCount( int mask ){
   int cnt=0;
   while( mask != 0 ){
      cnt++;
      mask &= mask-1;
   }
   return cnt;
}

int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
   int J,P,S,K;
   cin >> J >> P >> S >> K;
   vector<pair<int,pair<int,int> > > c;
   for( int i =0 ; i < J; i++ ){
      for( int j = 0 ; j <P; j++ ){
         for( int k = 0 ; k < S; k++ ){
            c.push_back( make_pair(i, make_pair(j, k)) );
         }
      }
   }
   int size = c.size();
   int ansMask = 0;
   for( int mask=0; mask < (1<<size); mask++){
      if( bitCount(ansMask) > bitCount( mask ) ) continue;
      bool ok = true;
      map<int,int> ab;
      map<int,int> bc;
      map<int,int> ac;
      for( int i = 0 ; i < size; i++){
         if( mask&(1<<i)){
            int A=c[i].first;
            int B=c[i].second.first;
            int C=c[i].second.second;
            ab[A*10+B]++;
            bc[B*10+C]++;
            ac[A*10+C]++;
            if( ab[A*10+B] > K || bc[B*10+C]> K || ac[A*10+C] > K ){
               ok=false;
               break;
            }
         }
      }
      if( ok ) ansMask=mask;
   }
   cout << "Case #" << loop+1 << ": " <<bitCount(ansMask)<< endl;
   /*
   for( int i = 0 ; i < size; i++ ){
      if( ansMask&(1<<i) ){
            int A=c[i].first;
            int B=c[i].second.first;
            int C=c[i].second.second;
            cout <<A+1 <<" " << B+1 <<" " << C+1 << endl;
      }
   }*/
  }
  return 0;
}
