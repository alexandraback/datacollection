#include <cstdio>
#include <algorithm>
using namespace std;

int caseCount = 0;
void make() {
  int n, s, p, p1, p2;
  scanf(" %d %d %d", &n, &s, &p);
  p1 = max(0, p-1);
  p2 = max(0, p-2);
  int res = 0, ss = 0;
  for (int i=0; i<n; ++i) {
    int k;
    scanf(" %d", &k);
    if (k >= p + 2 * p1) ++res;
    else if (k >= p + 2 * p2) ++ss;
  }
  printf("Case #%d: %d\n", ++caseCount, res + min(ss, s));
  return;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    make();
  }
}
