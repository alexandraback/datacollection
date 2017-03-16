#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int tt,cas,i,ans,n,starnum,cnt,mmax,idx;
  int require[1005][2];
  int state[1005];
  scanf("%d",&tt);
  for(cas = 1;cas <=  tt;++cas) {
    scanf("%d",&n);
    for(i = 1;i <= n;++i)
      scanf("%d %d",&require[i][0],&require[i][1]);
    ans = 0;
    cnt = 0;
    starnum = 0;
    memset(state,0,sizeof(state));
    while(1) {
      if(cnt == n) break;
      for(i = 1;i <= n;++i) {
        if(state[i] == 0 && starnum >= require[i][1]) break;
      }
      if(i <= n) {
        state[i] = 2;
        cnt++;
        ans++;
        starnum += 2;
      }
      else {
        for(i = 1;i <= n;++i) {
          if(state[i] == 1 && starnum >= require[i][1]) break;
        }
        if(i <= n) {
          state[i] = 2;
          cnt++;
          ans++;
          starnum += 1;
        }
        else {
          idx = -1;
          mmax = -1;
          for(i = 1;i <= n;++i) {
            if(state[i] == 0 && starnum >= require[i][0] && require[i][1] >= mmax) {
              mmax = require[i][1];
              idx = i;
            }
          }
          if(idx != -1) {
            state[idx] = 1;
            ans++;
            starnum += 1;
          }
          else break;
        }
      }
    }
    if(cnt == n) printf("Case #%d: %d\n",cas,ans);
    else printf("Case #%d: Too Bad\n",cas);
  }
}
