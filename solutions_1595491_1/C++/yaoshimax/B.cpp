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
  int scores[101];
  for( int i = 0 ; i < n_case ; i++ ){
    int N,S,p;
    cin >> N >> S >>p;
    int possible=0;
    int surprise_possible=0;
    //not suprising... [a, a, a](a) or [a, a, a+1]...(a+1) or [a, a+1, a+1]...(a+1)
    //surprising... [a, a, a+2] or [a, a+1, a+2] or [a, a+2, a+2] 
    for( int j = 0 ; j < N; j++ ){
      cin >> scores[j];
      if( scores[j]%3==0 ){
        //[a,a,a] or [a-1,a,a+1]
        if( scores[j]/3 >= p ) possible++;
        else if( scores[j]/3 +1 >= p && scores[j]/3-1 >= 0 )surprise_possible++;
      }
      else if( scores[j]%3 == 1){
        //[a,a,a+1] or [a-1, a+1, a+1]
        if( scores[j]/3+1 >= p ) possible++;
      }
      else{
        //[a,a+1,a+1] or [a, a, a+2]
        if( scores[j]/3+1 >= p ) possible++;
        else if( scores[j]/3 + 2 >= p ) surprise_possible++;
      }
    }
    //cout << possible << "," << surprise_possible<< "," <<S << endl;;
    cout << "Case #" << i+1 << ": " << possible+min(surprise_possible,S)<<endl;
  }
  return 0;
}

