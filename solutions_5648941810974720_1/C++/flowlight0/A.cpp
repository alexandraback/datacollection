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

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR",
                   "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void solve(){
  string S;
  cin >> S;

  int total = S.size();
  map<char, int> counter;
  for (auto c : S) counter[c]++;
  string res;
  
  
  while (total > 0){
    vector<int> can(10, 0);
    REP(i, 10){
      bool ok = true;
      map<char, int> dc;
      for (auto c : digits[i]) {
        if (++dc[c] > counter[c]) ok = false;
      }
      if (ok) can[i] = true;
    }
    
    int use = -1;
    // for (auto c : counter){
    //   cout << c << endl;
    // }
    // cout << can << endl;
    REP(i, 10) if (can[i]){
      bool go = false;
      for (auto c_ : counter){
        if (c_.second == 0) continue;
        char c = c_.first;
        if (digits[i].find(c) != string::npos){
          bool found = false;
          REP(j, 10) if (can[j] && j != i){
            if (digits[j].find(c) != string::npos){
              found = true;
            }
          }
          if (!found) go = true;
        }
      }
      if (go){
        use = i;
        break;
      }
    }

    // cout << digits[use] << endl;
    assert(use != -1);
    res.push_back(use + '0');
    for (auto c : digits[use]){
      counter[c]--;
    }
    total -= digits[use].size();
  }
  sort(ALL(res));
  cout << res << endl;
  
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
