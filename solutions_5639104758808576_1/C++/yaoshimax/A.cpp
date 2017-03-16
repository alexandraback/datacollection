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
    int n;
    string s;
    cin >> n >> s;
    int cnt=0;
    int ans=0;
    for( int j = 0 ; j <= n ; j++ ){
      if( s[j]=='0' && cnt < j+1 ){
         ans += j+1-cnt;
         cnt=j+1;
      }
      cnt+=s[j]-'0';
    }
    cout << "Case #" << loop+1 << ": " <<ans<< endl;
  }
  return 0;
}
