#include <algorithm>
#include <cstdio>

using namespace std;

int energy, r, n;
int v[10000010];
int sol(int cnt, int n, int e) {
  //printf("%d %d %d\n", cnt, n, e);
  if(cnt==n) return 0;
  int i, tmp, ans=0, nextE;
  for(i=0 ; i<=e ; i++) {
    if(e-i+r > energy) nextE = e;
    else nextE = e-i+r;
    tmp = v[cnt]*i + sol(cnt+1, n, nextE);
    if(tmp > ans) ans = tmp;
  }
  return ans;
}

int main() {
  int t, tt, i, j;
  scanf("%d", &tt);
  for(t=0; t<tt ;t++) {
    scanf("%d%d%d", &energy, &r, &n);
    for(i=0 ; i<n ; i++) {
      scanf("%d", &v[i]);
    }

    int ans = sol(0, n, energy);

    printf("Case #%d: %d\n", t+1, ans);
  }

}
