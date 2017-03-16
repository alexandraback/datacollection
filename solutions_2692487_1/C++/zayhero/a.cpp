#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

int a, n;
vi v;

void init()
{
  cin>>a>>n;
  v = vi(n);
  for(int i = 0; i < n; i++)
  {
    cin>>v[i];
  }
  sort(v.begin(), v.end());
}

int cal(int bg, int lt, int rt)
{
  int p;
  for(p = lt; p <= rt; p++)
  {
    if(bg <= v[p]) break;
    bg += v[p];
  }
  if(p > rt) return 0;
  if(bg <= 1) return 1 << 28;
  return 1 + cal(bg + bg - 1, p, rt);
}

void solve(int tcase)
{
  int res = n, bnd = 0;
  for(int i = n; i >= bnd; i--) // del from i - (n - 1)
  {
    int tmp = n - i + cal(a, 0, i);
    printf("%d %d\n", i, tmp);
    res = min(res, tmp);
  }
  printf("Case #%d: %d\n", tcase, res);
}

int main()
{
  int T;
  cin>>T;
  for(int i = 1; i <= T; i++)
  {
    init();
    solve(i);
  }
}