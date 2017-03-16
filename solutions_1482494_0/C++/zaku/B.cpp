#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int A[MAXN], B[MAXN];
int vis[MAXN];
int n;

void solve()
{
  memset(vis, 0, sizeof(vis));
  
  int flag;
  int stars = 0, ti = 0;
  for (;;) {
    flag = 1;
    for (int i = 0; i < n; ++i) {
      if (vis[i] == 2) continue;
      if (stars >= B[i]) {
	stars += 2-vis[i];
	++ti;
	vis[i] = 2;
	flag = 0;
      }
    }
    if (flag == 0) continue;

    int cur = 0, idx = -1;
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      if (stars >= A[i] && cur < B[i]) {
	cur = B[i];
	idx = i;
      }
    }
    if (idx != -1) {
      ++stars;
      ++ti;
      vis[idx] = 1;
      continue;
    }
    break;
  }

  if (stars == 2*n)
    printf("%d\n", ti);
  else
    puts("Too Bad");
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
      scanf("%d%d", A + i, B + i);

    printf("Case #%d: ", l);
    solve();
  }
  return 0;
}
