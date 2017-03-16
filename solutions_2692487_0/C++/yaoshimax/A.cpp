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
     int A,N;
     cin >> A >> N;
     vector<int> mote;
     for( int i = 0 ; i < N; i++ ){
      int tmp;
      cin >> tmp;
      mote.push_back(tmp);
     }
     sort( mote.begin(), mote.end() );
     int size = mote.size();
     int ans = INT_MAX;
     int curcount = 0;
     long long curscore = A;
     for( int i = 0 ; i <= size; i++ ){
       //cout << i << "... "<< size<<"-"<<i<<"+"<<curcount << endl;
       ans= min( size-i+curcount, ans );
       if( curscore <= mote[i] ){
        while( curscore <= mote[i] ){
          if( curscore -1 == 0 ){
            curcount = INT_MAX/2;
            break;
          }
          curscore += (curscore-1);
          curcount++;
        }
       }
       curscore += mote[i];
     }
     cout << "Case #" << loop+1 << ": " <<ans<< endl;
   }
   return 0;
}
