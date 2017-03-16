
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

int vs[1010];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    int n;
    scanf("%d", &n);
    REP(i, n){
      scanf("%d", &vs[i]);
    }
    sort(vs, vs+n);
    int res = 1000000000;
    for(int eat = 1; eat <= vs[n-1]; ++eat){
      int cost = eat;
      REP(i, n){
        int cur = vs[i];
        while(cur > eat){
          cur -= eat;
          ++cost;
        }
      }
      res = min(res, cost);
    }
    printf("Case #%d: %d\n", iCase+1, res);
  }
  return 0;
}
