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

Int main2() {
  Int ans = 0;
  int A, B; cin >> A >> B;

  vector<int> v;  
  for (int n = A; n <= B; n++) {
      char a[128]; 
      sprintf(a, "%d", n);
      
      int len = strlen(a);
      Int d = 1; REP(i, len) d *= 10;

      int m = n;
      v.clear();
      REP(i, len) {
          m = (m * 10 + a[i] - '0') % d;
          if (n < m && m <= B && find(ALL(v),m) == v.end()) {
              ans++;
              v.push_back(m);              
          }
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
