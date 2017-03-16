// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

char s[10005];
void solve() {
  static int cs=0;
  ++cs;
  printf("Case #%d: ", cs);
  fprintf(stderr, "Case #%d: ", cs);

  int ans = 0;
  scanf("%s", s);
  int n = strlen(s);
  s[n++] = '+';
  s[n++] = '\0';
  for(int i=0;i<n-1;i++) if(s[i]!=s[i+1]) ++ans;
  printf("%d\n", ans-1);
  fprintf(stderr, "%d\n", ans-1);
}

int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}
