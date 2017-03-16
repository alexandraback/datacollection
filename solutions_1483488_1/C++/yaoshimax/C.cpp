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
int length(int j ){
  int i = 0;
  while( j != 0 ){
    i++;
    j /= 10;
  }
  return i;
}
int main(){
  int n_case;
  cin >> n_case;
  bool checked[2000001];
  for( int i = 0 ; i < n_case ; i++ ){
    int A,B;
    cin >> A >> B;
    ll ans = 0;
    memset( checked, false, sizeof( checked ) );
    for( int j = A ; j <=B ; j++ ){
      if( checked[j] ) continue;
      else{
        ll sum = 1;
        int l = length(j);
        int num = j;
        int mask=1;
        for( int k = 0 ; k+1 < l; k++ ){ mask *= 10;}
        checked[num] = true;
        for( int k = 0 ; k < l ; k++ ){  
          int bit = num/mask;
          num = (num-bit*mask)*10+bit;
          if( num < mask || num > B || num < A ) continue;
          if( !checked[num] ){
            sum++;
            checked[num] = true;
          }
        }
        ans += sum*(sum-1)/2;
      }
    }
    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;
}

