// solution by Olivier Marty
// https://code.google.com/codejam/contest/4244486/dashboard#s=p0

#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr << #a << " = " << (a) << endl;

int R,C,W;

void parse() {
  scanf("%d%d%d", &R, &C, &W);
}

bool line[10];

int rec(int r, int c, int w, int tot) {
  if(w == 1)
    return tot + r*c;
  if(w == c)
    return tot + c;
  if(c >= 2*w)
    return rec(r, c-w, w, tot+1);
  // c > w et c < 2*w
  return tot+w+1;
}

int solve() {
  if(R > 1)
    return -1;
  return rec(R, C, W, 0);
}

int main() {
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    parse();
    printf("Case #%d: %d\n", i, solve());
		fprintf(stderr, "%d / %d = %.2f | %.2f\n", i, T, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * T) / CLOCKS_PER_SEC);
  }
}
