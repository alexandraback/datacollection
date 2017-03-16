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
cout.setf(ios::fixed, ios::floatfield);
  for( int loop = 0 ; loop < n_case ; loop++ ){
    int A, B;
    cin >> A>>B;
    vector<double> Ps;
    for(int i = 0 ; i < A ; i++ ){
      double tmp;
      cin >> tmp;
      Ps.push_back( tmp );
    }
    double ans = B+2;
    double Prob[100000];
    memset( Prob, 0 , sizeof(Prob) );
    Prob[0] = 1-Ps[0];
    for( int i = 0 ; i+1 < A; i++ ){
      Prob[i+1] = Prob[i]+(1-Prob[i])*(1-Ps[i+1]);
    }
    int rest = B-A;
    for( int n_erase = 0 ; n_erase+1 <= A; n_erase++ ){
      int n_succeed = rest+n_erase*2+1;
      int n_failed = n_succeed+B+1;
      double failed_prob = Prob[A-n_erase-1];
      //cout << n_succeed <<"*"<< (1-failed_prob)<<"+"<<  n_failed<<"*"<<failed_prob<<endl;
      double anstmp = (1-failed_prob)*n_succeed+(failed_prob) * n_failed;
      //cout << anstmp << endl;
      ans = min(anstmp,ans);
    }
    cout << "Case #" << loop+1 << ": ";
    cout <<setprecision(6) << ans<<endl;

  }
  return 0;
}

