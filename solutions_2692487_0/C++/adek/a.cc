/* Author: Adrian Zgorzałek
 *
 */

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

#define ASSERT_ for (;;) {}

typedef long long ll;
typedef long double ld;
typedef std::pair<int,int> PII;

#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)
#define REP(k,a) for(int k=0; k < (a); ++k)

#define INFTY 2000000000

using namespace std;

int solve(vector<int> &v, int pos, int me) {
  if (pos == (int)v.size()) return 0;
  if (me > v[pos]) return solve(v, pos+1, me+v[pos]);
  else {
    int penalty = 0;
    if (me <= 1) return v.size();
    else {
      while (me <= v[pos]) {
        me += me - 1;
        penalty++;
      }
    }
    return min(penalty + solve(v, pos+1, me + v[pos]), (int)v.size() - pos);
  }
}

int main() {
  int tests;
  scanf("%d", &tests);
  for (int testid = 1; testid <= tests;  testid++) {
    int me; int n;
    scanf("%d %d", &me, &n);
    vector<int> motes;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d",&x);
      motes.push_back(x);
    }
    sort(motes.begin(), motes.end());
    printf("Case #%d: %d\n", testid, solve(motes, 0, me));
  }
}
