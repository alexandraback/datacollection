#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SZ(a) ((int)((a).size()))
#define REPSZ(i,v) REP(i,SZ(v))
#define ALL(a) (a).begin(),(a).end()
typedef long long Int;

bool is_recycled(int n, int m) {
  char a[128], b[128];
  sprintf(a, "%d", n);
  sprintf(b, "%d", m);
  if (strlen(a) != strlen(b)) return false;
  string A(a);
  string B(b);
  A = A + A;
  return A.find(B) != string::npos;
}

Int main2() {
  Int ans = 0;
  int A, B; cin >> A >> B;
  for (int n = A; n <= B; n++)
      for (int m = A; m <= B; m++) {
          if (n < m && is_recycled(n,m)) {
              ans++;
          }
      }
  return ans;
}

int main() {
  int TNO; scanf("%d\n", &TNO);
  for(int tno = 1; tno <= TNO; tno++) {
      
    printf("Case #%d: ", tno);
    Int res = main2();
    cout << res << endl;
  }
  return 0;
}

// ./a.exe < B-large.in | tee B-large.res
