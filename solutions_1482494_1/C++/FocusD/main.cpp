#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int qq[1010][2];
int state[1010];

int main() {
  freopen("B-large.in","r",stdin);
  freopen("out.txt","w",stdout);
  int T, cass, i, ans, n, numm, cnt, maxn, idx;
  scanf("%d", &T);
  for(cass = 1; cass <= T; ++cass) {
    scanf("%d", &n);
    for(i = 1;i <= n;++i)
      scanf("%d %d", &qq[i][0], &qq[i][1]);
    ans = 0;
    cnt = 0;
    numm = 0;
    memset(state, 0, sizeof(state));
    while(1) {
      if(cnt == n)
        break;
      for(i = 1;i <= n;++i) {
        if(state[i] == 0 && numm >= qq[i][1])
          break;
      }
      if(i <= n) {
        state[i] = 2;
        cnt++;
        ans++;
        numm += 2;
      } else {
        for(i = 1; i <= n;++i) {
          if(state[i] == 1 && numm >= qq[i][1])
            break;
        }
        if(i <= n) {
          state[i] = 2;
          cnt++;
          ans++;
          numm += 1;
        } else {
          idx = -1;
          maxn = -1;
          for(i = 1;i <= n; ++i) {
            if(state[i] == 0 && numm >= qq[i][0] && qq[i][1] >= maxn) {
              maxn = qq[i][1];
              idx = i;
            }
          }
          if(idx != -1) {
            state[idx] = 1;
            ans++;
            numm += 1;
          }
          else break;
        }
      }
    }
    if(cnt == n)
      printf("Case #%d: %d\n",cass,ans);
    else
      printf("Case #%d: Too Bad\n",cass);
  }
}
