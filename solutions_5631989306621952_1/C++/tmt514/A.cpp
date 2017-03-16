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

int cs=0;
void solve() {
  ++cs;
  fprintf(stderr, "Case #%d: ", cs);
  printf("Case #%d: ", cs);

  char s[1005];
  scanf("%s", s);
  int n = strlen(s);
  string t = "";
  t += s[0];
  for(int i=1;i<n;i++) {
    if(t[0] <= s[i]) t = s[i] + t;
    else t = t + s[i];
  }
  printf("%s\n", t.c_str());
  fprintf(stderr, "%s\n", t.c_str());
}


int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) solve();  
  return 0;
}
