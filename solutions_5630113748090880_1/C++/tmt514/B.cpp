// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int cs=0;
void solve() {
  ++cs;
  fprintf(stderr, "Case #%d:", cs);
  printf("Case #%d:", cs);

  
  int n;
  scanf("%d", &n);
  map<int, int> a;
  for(int i=0;i<2*n-1;i++) {
    for(int j=0;j<n;j++)  {
      int x;
      scanf("%d", &x);
      a[x]++;
    }
  }
  vector<int> ans;
  for(auto &&it : a) {
    if(it.second % 2 == 1)
      ans.push_back(it.first);
  }
  sort(ans.begin(), ans.end());
  assert((int)ans.size() == n);
  for(int i=0;i<SZ(ans);i++) {
    printf(" %d", ans[i]);
    fprintf(stderr, " %d", ans[i]);
  }
  printf("\n");
  fprintf(stderr, "\n");

}


int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) solve();  
  return 0;
}
