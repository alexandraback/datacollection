#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int input[3500];
int flags[3500];

int c = 0, d = 0, v = 0;

void dfs(int pos, int now)
{
  flags[now] = 1;
  if(pos >= d)
    return;
  dfs(pos + 1, now + input[pos]);
  dfs(pos + 1, now);
}

int main()
{
  int T = 0;
  scanf("%d", &T);
  for(int Case = 1; Case <= T; ++Case)
  {
    memset(flags, 0, sizeof(flags));
    scanf("%d%d%d", &c, &d, &v);
    for(int i = 0; i < d; ++i)
      scanf("%d", input + i);
    dfs(0, 0);
    int ans = 0;
    for(int i = 1; i <= v; ++i)
    {
      if(flags[i] == 0)
      {
        flags[i] = 1;
        vector<int> vec;
        for(int j = 1; j + i <= v; ++j)
          if(i != j && flags[j] == 1)
            vec.push_back(i + j);
        for(int j = 0; j < (int)vec.size(); ++j)
          flags[vec[j]] = 1;
        ++ans;
      }
    }
    printf("Case #%d: %d\n", Case, ans);
  }
  return 0;
}
