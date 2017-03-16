#include <stdio.h>

int a[1010], b[1010];
int n;


int solve() {
    int used[1010][2]={0};
    int ans = 0;
    int allcor = 0;
    for (int i = 0;; ++i) {
        int cur = -1;
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (used[j][1]) {
               sum++;
               continue;
            }
            if (b[j] <= allcor) {
               cur = j;
               break;
            }
            if (used[j][0] == 0 && a[j] <= allcor) {
               if (cur == -1 || b[j] > b[cur]) {
                  cur = j;
               }
            }
        }
        if (cur == -1 && sum == n) break;
        if (cur == -1) return -1;
        if (b[cur] <= allcor ) {
           if (used[cur][0] == 1)
              allcor += 1;
           else allcor += 2;
           used[cur][1] = 1;
        }
        else {
           used[cur][0] = 1;
           allcor += 1;
        }
        ans++;
    }
    return ans;
}

int main () {
    int kase, i;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d", &kase);
    int h = 1;
    while (kase--) {
          scanf("%d", &n);
          for (int i = 0; i < n; ++i) {
              scanf("%d %d", &a[i], &b[i]);
          }
          printf("Case #%d: ", h++);
          int ans = solve();
          if ( ans == -1) {
             printf("Too Bad\n");
          }
          else {
               printf("%d\n", ans);
          }
    }
    return 0;
}
