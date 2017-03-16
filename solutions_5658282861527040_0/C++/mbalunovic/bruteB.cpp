#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a, b, k, cnt[1010];

void solve (int c) {
  memset(cnt, 0, sizeof(cnt));

  scanf("%d %d %d",&a,&b,&k);
  for (int x = 0; x < a; ++x)
    for (int y = 0; y < b; ++y)
      ++cnt[x & y];

  int res = 0;
  
  for (int x = 0; x < k; ++x)
    res += cnt[x];

  printf("Case #%d: %d\n",c,res);
}

int main (void) {
  int t;
  scanf("%d",&t);
  for (int c = 1; c <= t; ++c)
    solve(c);
  return 0;
}
