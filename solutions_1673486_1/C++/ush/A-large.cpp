
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long integer;


double vs[100010];
double ps[100010];
int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    int nCur, nTotal;
    cin >> nCur >> nTotal;
    double prev = 1.0;
    ps[0] = 0;
    REP(i, nCur){
      cin >> vs[i];
      ps[i+1] = ps[i] + prev * (1- vs[i]);
      prev = prev * vs[i];
    }
    ps[nCur+1] = ps[nCur] + prev;
    
    double res = 1 + nTotal + 1; // first Enter
    for(int bs = 0; bs <= nCur; ++bs){
      double cur = 0;
      int num1 = 2*bs + nTotal - nCur + 1;
      int num2 = num1 + nTotal + 1;
//       cur = ps[1...nCur-bs] * num2 + ps[nCur-bs+1...nCur+1]*num1
      cur = (ps[nCur+1] - ps[nCur-bs]) * num1 + ps[nCur-bs] * num2;
      res = min(res, cur);
    }
    printf("Case #%d: %.10f\n", iCase+1, res);
  }
  
  return 0;
}
