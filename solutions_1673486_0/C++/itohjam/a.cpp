#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)x)<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define EREP(i,a,b) for(int i=a;i<=b;i++)
#define erep(i,n) EREP(i,0,n)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

int A, B;
double p[100002], mul[100002];

double solve(){
  double res = 999999999;

  for(int i = 0; i <= A; i++){
    int del = A - i;
    double ex =
      mul[i] * (del + del + (B - A) + 1) +
      (1 - mul[i]) * (del + del + (B - A) + 1 + B + 1);
    res = min(res, ex);
  }

  return min(res, 1.0 * (1 + B + 1));
}

int main(void){
  int T;
  cin >> T;

  for(int SET = 1; SET <= T; SET++){
    cin >> A >> B;

    mul[0] = 1.0;
    for(int i = 0; i < A; i++){
      cin >> p[i];
      mul[i + 1] = mul[i] * p[i];
    }

    printf("Case #%d: %.10f\n", SET, solve());
  }
}
