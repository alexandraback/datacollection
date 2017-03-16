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

void main2() {
  int N; cin >> N;
  vector<int> a(N), b(N);
  REP(i, N) cin >> a[i] >> b[i];
  vector<int> done(N);
  
  int play = 0;
  int have = 0;
  for (;;) {
      if (have == 2 * N) break;
      int hard, idx;
      REP(i, N) {
          if (b[i] <= have && done[i] != 2) {
              have += 2 - done[i];
              done[i] = 2;
              goto END;
          }
      }

      hard = -1, idx = -1;
      REP(i, N) {
          if (a[i] <= have && done[i] == 0) {
              if (hard < b[i]) {
                  hard = b[i];
                  idx = i;
              }
          }
      }
      if (idx == -1) {
          cout << "Too Bad" << endl;
          return;
      } else {
          done[idx] = 1;
          have++;
      }
  END:;
      play++;
  }
  cout << play << endl;
}

int main() {
  int TNO; scanf("%d\n", &TNO);
  for(int tno = 1; tno <= TNO; tno++) {
      
    printf("Case #%d: ", tno);
    main2();
  }
  return 0;
}

// ./a.exe < B-large.in | tee B-large.res
