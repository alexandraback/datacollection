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
#include <iomanip>
 
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
    int n_level;
    cin >> n_level;
    vector<pair<int,int> > vec;
    for( int i = 0 ; i < n_level ; i++ ){
      int first,second;
      cin >> first >> second;
      vec.push_back( make_pair( second,first ) );
    }
    sort( vec.begin(), vec.end() );
    int n_star = 0;
    int num = 0;
    for( int i = 0 ; i < n_level ;i++ ){
      if( n_star < vec[i].first ){
        bool flag = false;;
        for( int j = n_level-1 ; j >=0 ;j-- ){
          if( vec[j].second == -1 ) continue;
          if( n_star >= vec[j].second ){
            n_star++;
            //cout << "erase " << vec[j].second << endl;
            vec[j].second = -1;
            flag = true;
            break;
          }
        }
        if( flag == false ){
          num = -1;
          break;
        }
        i--;
      }
      else{
        if( vec[i].second == -1 ){
          n_star++;
          //cout << "erase " << vec[i].first << endl;
        }
        else{
          //cout << "erase " << vec[i].first <<","<< vec[i].second << endl;
          vec[i].second = -1;
          n_star+=2;
        }
      }
      //cout << n_star << endl;
      num++;
    }
    if( num == -1 )
    cout << "Case #" << loop+1 << ": "<< "Too Bad"<<endl;
    else
      cout << "Case #" << loop+1 << ": "<< num<<endl;
  }
  return 0;
}

