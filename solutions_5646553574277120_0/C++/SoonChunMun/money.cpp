#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int t,c,d,v,denom[110];

int main() {
  scanf("%d", &t);
  for (int ca=1; ca<=t; ca++) {
    int ans = 0;
    scanf("%d %d %d", &c, &d, &v);

    for (int i=0; i<d; i++) scanf("%d", &denom[i]);

    int reachable = 0;
    for (int i=0; i<d; i++) {
      while (reachable < denom[i]-1) {
        ans++;
        reachable = c*(reachable+1) + reachable;
      }
      reachable += c * denom[i];
    }

    while (reachable < v && reachable <= 10e9 && reachable >= 0) {
       ans++;
       reachable = c*(reachable+1) + reachable;
    }

    printf("Case #%d: %d\n", ca, ans);
  }
  return 0;
}
