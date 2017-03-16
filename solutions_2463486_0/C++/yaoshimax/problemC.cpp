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

string ltos( long long i){
  stringstream ss;
  ss << i;
  string num = ss.str();
  return num;
}
bool palstr( string str){
  int size = str.size();
  bool ok = true;
  for( int i = 0 ; i < (size+1)/2;i++){
    if( str[i] != str[size-1-i] ){
      ok = false;
      break;
    }
  }
  return ok;
}
bool pal( long long i ){
  string num = ltos(i);
  return palstr(num );
}
int main(){
   vector< long long > pals;
   for( long long  i = 1 ; i* i <= 100000000000000LL ; i++ ){
    if( pal(i) && pal(i*i) ){
      pals.push_back( i*i );
      cerr << i * i << ", ";
    }
   }
   cerr << "Finished" << endl;
   int n_case;
   cin >> n_case;
   for( int loop = 0 ; loop < n_case ; loop++ ){
     long long A,B;
     cin >> A >> B;
     cout << "Case #" << loop+1 << ": "<<(upper_bound(pals.begin(),pals.end(),B)-upper_bound(pals.begin(),pals.end(),A-1)) <<endl;
   }
   return 0;
}
