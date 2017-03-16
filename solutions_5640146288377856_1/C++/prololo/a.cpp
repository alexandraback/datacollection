#include <cstdio>
#include <cassert>

int solve_problem ()
{
  int r, c, w;
  int ans = 0;
  assert(scanf("%d %d %d", &r, &c, &w)!=EOF);
  if (c%w == 0){
    ans = (c/w) * r + w - 1;
  } else {
    ans = (c/w) * r + w;
  }
  return ans;
}


int main ()
{
  int t;
  int ans;
  assert(scanf("%d", &t)!=EOF);
  for (int i = 1; i <= t; i++){
    ans = solve_problem();
    printf("Case #%d: %d\n", i, ans);
  }
}
