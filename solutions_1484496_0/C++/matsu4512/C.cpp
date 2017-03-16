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
using namespace std;
static const double EPS = 1e-10;
static const double PI = 3.141592653589;
typedef long long ll;

struct SS{
  int bit;
  int sum;
  vector<int> v;
};

bool order(SS s1, SS s2){
  return s1.sum < s2.sum;
}

void solve(){
  int N;
  vector<int> S;
  vector<vector<int> > result;
  cin >> N;
  for (int i = 0; i < N; ++i){
    int a;
    cin >> a;
    S.push_back(a);
  }

  vector<SS> P;
  for(int i = 1; i < (1<<20); i++){
    SS s;
    s.sum = 0;
    s.bit = i;
    for(int j = 0; j < 20; j++){
      if((i>>j)&1){
	s.sum += S[j];
	s.v.push_back(S[j]);
      }
    }
    P.push_back(s);
  }

  for(int i = 0; i < P.size(); i++){
    for(int j = 0; j < P.size(); j++){
      if(i == j) continue;
      if(P[i].bit & P[j].bit > 0) continue;
      if(P[i].sum != P[j].sum) continue;
      for(int k = 0; k < P[i].v.size(); k++){
	cout << P[i].v[k];
	if(k != P[i].v.size()-1) cout << " ";
      }
      cout << endl;

      for(int k = 0; k < P[j].v.size(); k++){
	cout << P[j].v[k];
	if(k != P[j].v.size()-1) cout << " ";
      }
      cout << endl;
      return;
    }
  }
  cout << "impossible" << endl;
}

int main(){
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i){
    cout << "Case #" << i << endl;
    solve();
  }
  return 0;
}
