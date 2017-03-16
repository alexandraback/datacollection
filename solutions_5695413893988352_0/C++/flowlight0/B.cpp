#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

template <typename S, typename T> ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  REP(i, v.size()){
    if (i > 0) out << ", ";
    out << v[i];
  }
  out << "]";
  return out;
}

typedef long long ll;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;

void solve(){
  string C, J;
  cin >> C >> J;

  string AC = C, AJ = J;
  replace(ALL(AC), '?', '0');
  replace(ALL(AJ), '?', '0');
  
  {                             // is it possible that C == J?
    bool ok = true;
    REP(i, C.size()){
      if (C[i] != '?' && J[i] != '?' && C[i] != J[i]){
        ok = false;
      }
    }
    if (ok){
      REP(i, C.size()){
        char c = C[i] == '?' ? J[i] == '?' ? '0' : J[i] : C[i];
        AC[i] = AJ[i] = c;
      }
    }
  }

  REP(i, C.size()){
    REP(cd, 10) if (C[i] == '?' || C[i] == ('0' + cd)){
      REP(jd, 10) if (J[i] == '?' || J[i] == ('0' + jd)){
        if (cd == jd) continue;
        string TC = C;
        string TJ = J;
        TC[i] = ('0' + cd);
        TJ[i] = ('0' + jd);
        REP2(j, i + 1, C.size()){
          if (TC[j] == '?') TC[j] = (cd < jd ? '9' : '0');
          if (TJ[j] == '?') TJ[j] = (cd < jd ? '0' : '9');
        }

        ll ac_num = atoll(AC.c_str()), aj_num = atoll(AJ.c_str());
        ll tc_num = atoll(TC.c_str()), tj_num = atoll(TJ.c_str());
        if (abs(tc_num - tj_num) < abs(ac_num - aj_num) ||
            (abs(tc_num - tj_num) ==  abs(ac_num - aj_num) &&
             (tc_num < ac_num ||
              (tc_num == ac_num && tj_num < aj_num)))) {
          AC = TC;
          AJ = TJ;
        }
      }
    }
    
    
    if (C[i] != '?' && J[i] != '?' && C[i] != J[i]){
      break;
    } else {
      char c = C[i] == '?' ? J[i] == '?' ? '0' : J[i] : C[i];
      C[i] = J[i] = c;
    }
  }
  cout <<AC << " " << AJ << endl;
}
 
int main(){
  int T;
  cin >> T;
  REP(t, T){
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}
