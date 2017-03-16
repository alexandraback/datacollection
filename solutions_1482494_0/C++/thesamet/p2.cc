#include <assert.h>
#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

void run() {
  int n;
  cin >> n;
  int a[1000], b[1000];
  int played[1000];
  REP(i, n) {
    cin >> a[i] >> b[i];
    played[i] = 0;
  }
  int s = 0;
  int first_s;
  int games = 0;
  while (1) {
    int first_s = s;
    bool found = true;
    while (found) {
      found = false;
      for (int i = 0; i < n; ++i) {
        if (b[i] <= s && played[i] < 2) {
          s += 2 - played[i];
          played[i] = 2;
          found = true;
          ++games;
        }
      }
    }
    REP(i,n) {
      if (played[i] == 0) {
        assert(b[i] > s);
      }
    }
    int has_max_b = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] <= s && played[i] < 1) {
        if (has_max_b == -1 || b[i] > b[has_max_b]) {
          has_max_b = i;
        }
      }
    }
    if (has_max_b != -1) {
      s += 1;
      played[has_max_b] = 1;
      ++games;
    }
    if (first_s == s) {
      break;
    }
  }
  if (s == 2 * n) {
    REP(i, n)  {
      assert(played[i] == 2);
    }
    cout << games << endl;
  } else {
    cout << "Too Bad" << endl;
  }
}

int main(){
  freopen("x.in", "r", stdin);
  freopen("x.out", "w", stdout);
  cout.precision(12);
  cout.setf(ios::fixed);
  int ctest = 0, tests = 0;
  for(cin >> tests; ctest++ < tests; run()) {
    printf("Case #%d: ", ctest);
  }
  return 0;
}
