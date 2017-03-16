#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <fstream>
#include <cmath>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define ITER(c) __typeof((c).begin())
#define PB(e) push_back(e)
#define FOREACH(i, c) for(ITER(c) i = (c).begin(); i != (c).end(); ++i)
#define MP(a, b) make_pair(a, b)
#define PARITY(n) ((n) & 1)

typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-10;

const int sz = 20010;
double prob[sz + 1][sz / 2 + 1];

double solve(){
  int N, X, Y;
  cin >> N >> X >> Y;
  if(X == 0 && Y == 0) return 1.0;

  int S = 1;
  int D = abs(X) + abs(Y);
  assert(D > 0);

  for(int i = 1; i < D - 1; i += 2){
    S = S + 2 * i + 3;
    if(N < S) return 0.0;
  }

  int S1 = S;
  int S2 = S + 2 * (D - 1) + 3;
  // int S3 = S2 + 2 * (D + 1) + 3;
  // int S4 = S3 + 2 * (D + 3) + 3;
  // cout << S1 << " " << S2 << endl;
  // cout << S3 << " " << S4 << endl;
  if(N < S1 ) return 0.0;
  if(S2 <= N) return 1.0;
  if(X == 0 ) return S2 == N ? 1.0 : 0.0;

  int need  = Y + 1;
  int other = D;
  int rest  = N - S1;
  // cout << need << " " <<rest << " " << other << endl;


  if(other + need <= rest) return 1.0;

  double ans = 1.0;
  
  for(int i = 0; i < need; i++){
    
    // rest回中i回とo回に分かれた
    ans -= prob[rest][min(i, rest - i)];
  }
  
  return ans;
}

int main(){
  
  prob[0][0] = 1.0;
  REP(n, sz){
    REP(i, sz / 2){
      prob[n+1][i] += prob[n][i] / 2;
      prob[n+1][i+1] += prob[n][i] / 2;
    }
  }
  
  
  int T;
  cin >> T;
  REP(t, T){
    printf("Case #%d: %.20lf\n", t + 1, solve());
  }
  return 0;
}
