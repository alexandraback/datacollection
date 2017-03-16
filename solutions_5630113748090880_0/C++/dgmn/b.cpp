#include <bits/stdc++.h>

using namespace std;

int cnt[2501];
vector<int> ans;

int main()
{
  int t, a, n, cas = 0;
  scanf("%d", &t);
  while(t--)
  {
    memset(cnt, 0, sizeof cnt);
    scanf("%d", &n);
    for(int i = 0; i < 2*n - 1; ++i)
      for(int j = 0; j < n; ++j)
      {
        scanf("%d", &a);
        ++cnt[a];
      }
    ans.clear();
    for(int i = 1; i <= 2500; ++i)
      if(cnt[i]&1)
        ans.push_back(i);
    sort(ans.begin(), ans.end());
    printf("Case #%d:", ++cas);
    for(int i = 0; i < ans.size(); ++i)
      printf(" %d", ans[i]);
    puts("");
  }
  return 0;
}
