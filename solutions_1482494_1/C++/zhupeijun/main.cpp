#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tre[1010][2];
int dfd[1010];

int main()
{
  freopen("B-large.in","r",stdin);
  freopen("out.txt","w",stdout);
  int cases, u, i, ans, n, numm, cnt, maxn, idx;
  scanf("%d", &cases);
  for(u = 1; u <= cases; ++u)
  {
    scanf("%d", &n);
    for(i = 1;i <= n;++i)
      scanf("%d %d", &tre[i][0], &tre[i][1]);
    ans = 0;
    cnt = 0;
    numm = 0;
    memset(dfd, 0, sizeof(dfd));
    while(1)
    {
      if(cnt == n)
        break;
      for(i = 1;i <= n;++i)
      {
        if(dfd[i] == 0 && numm >= tre[i][1])
          break;
      }
      if(i <= n)
      {
        dfd[i] = 2;
        cnt++;
        ans++;
        numm += 2;
      }
      else
      {
        for(i = 1; i <= n;++i)
        {
          if(dfd[i] == 1 && numm >= tre[i][1])
            break;
        }
        if(i <= n)
        {
          dfd[i] = 2;
          cnt++;
          ans++;
          numm += 1;
        }
        else
        {
          idx = -1;
          maxn = -1;
          for(i = 1;i <= n; ++i)
          {
            if(dfd[i] == 0 && numm >= tre[i][0] && tre[i][1] >= maxn)
            {
              maxn = tre[i][1];
              idx = i;
            }
          }
          if(idx != -1)
          {
            dfd[idx] = 1;
            ans++;
            numm += 1;
          }
          else break;
        }
      }
    }
    if(cnt == n)
      printf("Case #%d: %d\n",u,ans);
    else
      printf("Case #%d: Too Bad\n",u);
  }
}
