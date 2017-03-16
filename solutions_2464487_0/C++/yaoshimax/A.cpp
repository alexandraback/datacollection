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
     long long r,t;
     cin >> r >> t;

     long long ans = -(1+r);
     double dr = r;
     double sq = sqrt((2*dr-1)*(2*dr-1)+8*t);
     long long k = (long long)sq;
     //cout <<sq << "," <<k << endl;
     ans = (k - 2*r+1)/4;

     cout << "Case #" << loop+1 << ": " <<ans<< endl;
   }
   return 0;
}
