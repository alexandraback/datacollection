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

int main2() {
  int N; cin >> N;
  int S; cin >> S;
  int P; cin >> P;
  int t[P];
  REP(i, N) cin >> t[i];
  sort(t, t + N);
  reverse(t, t + N);
  int ans = 0;
  int done = 0;
  REP(i, N) {
      int x = t[i];
      
      int normal = (x / 3) + !!(x % 3);
      int surp = normal + ((x % 3) == 1 ? 0 : 1);
      if (surp > 10) surp = 10;
      if (x == 0) surp = 0;
          
      if (normal >= P) ans++;
      else if (surp >= P && done < S) {done++; ans++;}
  }
  return ans;
}

int main() {
  int TNO; scanf("%d\n", &TNO);
  for(int tno = 1; tno <= TNO; tno++) {
    printf("Case #%d: ", tno);
    int res = main2();
    cout << res << endl;
  }
  return 0;
}
