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
    int T;
    cin >> T;
    priority_queue<int> q;
    for( int i = 0 ; i < T; i++ ){
      int p;
      cin >> p;
      q.push(p);
    }
    int left = 0;
    int right = 1001;
    while( left+1 < right ){
      int mid = (left+right)/2;
      bool ok = false;
      for( int i = 0 ; i < mid; i++ ){
         priority_queue<int> pq = q;
         int n_special = 0;
         int n_max = mid-i;
         while( n_special <= i && !pq.empty() ){
            int top = pq.top();
            if( n_max >= top ){
              ok=true; 
              break;
            }
            if( n_special == i ){
               break;
            }
            pq.pop();
            n_special+=1;
            //cout << "rest:"<<top-n_max << endl;
            if( top-n_max > n_max ){
               pq.push(top-n_max);
            }
         }
         if(pq.empty()) ok=true;
         if( ok ){
            //cout << mid <<": "<< i << ", "<< pq.size()<<endl;
            break;
         }
      }
      if( ok ){
         right = mid;
      }
      else{
         left = mid;
      }
    }
    cout << "Case #" << loop+1 << ": " <<right<< endl;
  }
  return 0;
}
