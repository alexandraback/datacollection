#include <stdio.h>
#include <map>
#include <vector>

#define FOR(q,n) for(int q=0; q<n; q++)
#define FOREACH(it, t) for(__typeof(t.begin()) it=t.begin(); \
    it!= t.end(); ++it)
using namespace std;

void solve(int _case) {
  map<int, int> back[1000];
  int n;
  scanf("%d", &n);
  back[0][0] = 0;
  FOR(q, n) {
    int x;
    scanf("%d", &x);
    FOREACH(it, back[q]) back[q+1][it->first] = 0;
    FOREACH(it, back[q]) back[q+1][it->first + x] = x;
    FOREACH(it, back[q]) back[q+1][it->first - x] = - x;
  }

  printf("Case #%d:\n", _case);
  vector<int> a,b;
  int t = n;
  int v = 0;
  while (t) {
    if (back[t][v] > 0) {
      a.push_back(back[t][v]);
    } else if (back[t][v] < 0) {
      b.push_back(-back[t][v]);
    }
    v -= back[t][v];
    t--;
  }
  if (!a.empty() ) {
    FOR(q, (int) a.size()) {
      if (q) printf(" ");
      printf("%d", a[q]);
    }
    printf("\n");
    FOR(q, (int) b.size()) {
      if (q) printf(" ");
      printf("%d", b[q]);
    }
    printf("\n");
  } else {
    printf("Impossible\n");
  }

}

int main() {
  int t;
  scanf("%d", &t);
  FOR(q, t) solve(q+1);

}
