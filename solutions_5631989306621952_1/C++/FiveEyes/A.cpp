#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iterator>
#define FOR(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define foreach(itr,c) for(decltype((c).begin()) itr=(c).begin(); itr != (c).end(); itr++)
#define MP(a,b) make_pair(a,b)

using namespace std;

char s[2500], out[3500];

int n;

char * solve() {
  char *p, *pe;
  p = pe = &out[1500];
  memset(out, 0, sizeof(out));
  FOR(i, 0, n) {
    *(p-1) = s[i];
    *pe = s[i];
    if(strcmp(p-1, p) < 0) {
      pe++;
    } else {
      *pe = 0;
      p--;
    }
  }
  return p;
}

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  //freopen("A-small-attempt0.in", "r", stdin);
  //freopen("A-small-attempt0.out", "w", stdout);
  int t;
  cin >> t;
  FOR(tt, 1, t + 1) {
    cin >> s;
    n = strlen(s);
    char *ans = solve();
    printf("Case #%d: %s\n", tt, ans);
  }
  return 0;
}
