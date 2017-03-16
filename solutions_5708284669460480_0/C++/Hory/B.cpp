#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int k = 0, l = 0, s = 0;
int keyboard[26];
char target[10];
char nowstr[10];

double dfs(int now)
{
  double ans = 0;
  if(now >= s)
  {
    for(int i = 0; nowstr[i] != 0; ++i)
    {
      bool isok = true;
      if(i + l > s)
        break;
      for(int j = 0; target[j] != 0; ++j)
        if(nowstr[i + j] != target[j])
        {
          isok = false;
          break;
        }
      if(isok)
        ++ans;
    }
    return ans;
  }
  for(int i = 0; i < 26; ++i)
  {
    if(keyboard[i] == 0)
      continue;
    nowstr[now] = i + 'A';
    ans += keyboard[i] / (double)k * dfs(now + 1);
  }
  return ans;
}

int main()
{
  int T = 0;
  scanf("%d", &T);
  for(int Case = 1; Case <= T; ++Case)
  {
    scanf("%d%d%d", &k, &l, &s);
    memset(keyboard, 0, sizeof(keyboard));
    {
      char tmp[10];
      scanf("%s%s", tmp, target);
      for(int i = 0; tmp[i] != 0; ++i)
        ++keyboard[tmp[i] - 'A'];
    }
    double ans = 0;
    {
      bool isok = true;
      for(int i = 0; target[i] != 0; ++i)
        if(keyboard[target[i] - 'A'] == 0)
        {
          isok = false;
          break;
        }
      if(!isok)
      {
        printf("Case #%d: %.8f\n", Case, 0.0);
        continue;
      }
    }
    int prelen = l;
    for(int i = 1; target[i] != 0; ++i)
    {
      bool isok = true;
      for(int j = 0; target[i + j] != 0; ++j)
        if(target[i + j] != target[j])
        {
          isok = false;
          break;
        }
      if(isok)
      {
        prelen = i;
        break;
      }
    }
    ans = 1 + (s - l) / prelen;
    //printf(">>>%.8f\n", ans);
    ans -= dfs(0);
    printf("Case #%d: %.8f\n", Case, ans);
  }
  return 0;
}
