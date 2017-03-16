#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cctype>
#include <set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i< n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;
const double EPS = 1e-10;

const int SZ = 100010;
double p[SZ];

int main(){
  int T, A, B;
  cin >> T;
  rep(t, T){
    cin >> A >> B;
    double nomiss = 1.0;
    double best = B + 2;

    rep(i, A + 1){
      if(i != A) cin >> p[i];
      int d = A - i;
      best = min(best,nomiss*(2*d+B-A+1) + (1-nomiss) * (2*d+2*B-A+2));
      //      cout << nomiss*(2*d+B-A+1) + (1-nomiss) * (2*d+2*B-A+2) << endl;;
      if(i != A) nomiss *= p[i];
    }
    cout << "Case #" << fixed << setprecision(6) << t + 1 << ": "<< best << endl;
  }
  return 0;
}
