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
     int E,R,N;
     cin >> E >> R>> N;
     vector<int> act;
     for( int i = 0 ; i < N ;i++){
      int tmp;
      cin >> tmp;
      act.push_back(tmp);
     }
     int ans = 0;
     int curE = E;
     for( int i = 0 ; i < N ;i++){
        if(i+1 < N && act[i]<act[i+1] ){
          int nextE = min(curE+R,E);
          int consume = max(curE-(nextE-R),0);
          ans += consume * act[i];
          curE = nextE;
        }
        else{
          ans += curE*act[i];
          curE = R;
        }
     }
     cout << "Case #" << loop+1 << ": " <<ans<< endl;
   }
   return 0;
}
