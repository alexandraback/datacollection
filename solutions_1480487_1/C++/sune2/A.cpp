#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

template<class T> T lower_search(T lb, T ub, bool (*C)(T,int), int now) {
  REP(i,100) {
    T mid = (lb+ub)/2;
    if (C(mid, now)) ub = mid;
    else lb = mid;
  }
  return ub;
}
int s[200];
int sum;
int n;
bool C(double x, int now) {
  double p = s[now]+x*sum;
  double hoge = x;
  REP(i,n) {
    if (i==now) continue;
    double y = max(0.0,(p-s[i])/sum);
    hoge += y;
  }
  return hoge>=1;
}

int main() {
  int T;
  cin >> T;
  REP(t,T) {
    cin >> n;
    sum = 0;
    REP(i,n) {
      cin >> s[i];
      sum += s[i];
    }
    printf("Case #%d:", t+1);
    REP(i,n) {
      double ans = lower_search<double>(0,1,C,i);
      printf(" %.7f", ans*100);
    }
    cout << endl;
  }
}
