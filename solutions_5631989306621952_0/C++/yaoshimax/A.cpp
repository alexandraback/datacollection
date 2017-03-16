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
   string inStr;
   cin >> inStr;
   string ansStr=inStr.substr(0,1);
   for( int i = 1 ;  i < (int) inStr.size(); i++ ){
      string firstStr=inStr[i]+ansStr;
      string lastStr=ansStr+inStr[i];
      ansStr=max(firstStr,lastStr);
   }
   cout << "Case #" << loop+1 << ": " <<ansStr<< endl;
  }
  return 0;
}
