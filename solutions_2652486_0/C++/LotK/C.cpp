#include <algorithm>
#include <cstdio>

using namespace std;

int r, n, m, k, check;
int guess[5], guess2[5], subset[10], ans[5];
int gen(int cnt, int n) {
  if(check==1) return 0;
  int i, j;
  if(cnt==n) {
    for(i=0 ; i<n ; i++) guess2[i] = guess[i];
    sort(guess2, guess2+n);

    for(i=0 ; i<k ; i++) {
      int tmp = subset[i];
      for(j=n-1 ; j>=0 ; j--) {
        if(tmp%guess[j]==0) {
          tmp/=guess[j];
        }
      }
      if(tmp>1) break;
    }
    if(i==k) {
      for(j=0 ; j<n ; j++) {
        ans[j]=guess2[j];
      }
      check=1;
    }
    return 0;
  }

  for(i=2 ; i<=m ; i++) {
    guess[cnt]=i;
    gen(cnt+1, n);
  }
}

int main() {
  int t, tt, n, i, j;
  scanf("%d", &tt);
  for(t=0 ; t<tt ; t++) {
    printf("Case #%d:\n", t+1);

    scanf("%d%d%d%d", &r, &n, &m, &k);
    for(i=0 ; i<r ; i++) {
      for(j=0 ; j<k ; j++) {
        scanf("%d", &subset[j]);
      }
      for(j=0 ; j<n ; j++) ans[j]=2;
      check = 0;
      gen(0, n);

      for(j=0 ; j<n ; j++) {
        printf("%d", ans[j]);
      }
      printf("\n");
    }
  }
}
