#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
#define pb         push_back
#define all(a)     (a).begin(),(a).end()
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(int i=0; i<n; ++i)
#define REP(i,j,k) for(int i=j; i<k; ++i)
#define each(a,b)  for (__typeof((a).begin()) b=(a).begin(); b!=(a).end(); b++)

typedef long long ll;
int    INF = 100000000;
double EPS = 1e-8;

int main () {
  int T; cin >> T;
  rep (t, T) {
    double C, F, X;
    cin >> C >> F >> X;
    double result = 1e8;

    rep (b, 10000) {
      double a = 0;
      rep (i, b) {
        a += C/(2+i*F);
      }
      result = min(result, a+X/(b*F+2));
    }

    cout << "Case #" << t+1 << ": ";
    printf("%.8lf\n", result);
  }
  return 0;
}
