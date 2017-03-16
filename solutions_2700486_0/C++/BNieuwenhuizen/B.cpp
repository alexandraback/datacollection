
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;


double ncr[2003][2003];

void ncrCalc() {
  for(int i = 0; i < 2003; ++i)
    ncr[i][0] = 1;
  for(int i = 1; i < 2003; ++i) {
    for(int j = 1; j <= i; ++j) {
      ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
    }
  }
}
double dist(int a, int b, int m) {
  assert (b > 0 && b <= 2*m);
  //cout << " " << a << " " << b << " " << m << endl;
  if(a == 0)
    return 1.0;
  if(a > b)
    return 0.0;
  double p1 = 0.0;
  double p2 = 0.0;
  for(int i = 0; i <= b; ++i) {
    if(b-i > m || i > m) continue;
    assert(b < 2003 && i < 2003);
    double pp = ncr[b][i];

    //cerr << i << " " << (b-i) << " " << pp << endl;
    (i < a ? p1 : p2) += pp;
  }
  if(p2 == 0.0)
    abort();

  //cerr << a << "  "<< b << "  "<< m << ": " << p1 << " " << p2 << endl;
  return p2/(p1+p2);
}
void doit (int casenum) {
  int N, X, Y;
  cin >> N >> X >> Y;
  //cout << N << " " << X << "  "<< Y << endl;
  double prob = 0.0;

  int k = 1+ (Y + abs(X));
  if(k*(k+1)/2 <= N)
    prob = 1.0;
  else if((k-2)*(k-1)/2 >= N) 
    prob = 0.0;
  else if(X != 0) {
    int m = Y + abs(X);
    N -= (k-2)*(k-1)/2;
    prob = dist(Y+1, N, m);
  }

  assert(prob >= 0.0 && prob <= 1.0);
  cout.precision(10);
  cout.setf(ios::fixed, ios::floatfield);
  cout << "Case #" << casenum << ": " << prob << endl;
}

int main () {
  ncrCalc();
  int t;
  cin >> t; //scanf ("%d ", &t);
  for (int i = 0; i < t; i++) {
    doit (i+1);
  }
  return 0;
}

