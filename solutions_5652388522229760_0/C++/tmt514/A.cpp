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

void solve() {
  static int cs=0;
  ++cs;

  int n;
  scanf("%d", &n);
  printf("Case #%d: ", cs);
  fprintf(stderr, "Case #%d: ", cs);

  if (n == 0) {
    printf("INSOMNIA\n");
    fprintf(stderr, "INSOMNIA\n");
    return;
  }
  int c[10]={};
  for (int v = n; ; v += n) {
    int w=v;
    while(w) { c[w%10]=1; w/=10; }
    int flag=0;
    for(int i=0;i<10;i++) if(c[i]==0) flag=1;
    if(!flag) {
      printf("%d\n", v);
      fprintf(stderr, "%d\n", v);
      return;
    }
  }
}

int main(void) {
  int T;
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}
