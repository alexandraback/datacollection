#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void solve()
{
  static const int kMaxN = 110;
  static int mp[kMaxN][kMaxN];
  static int hi[2][kMaxN];
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i) hi[0][i] = 0;
  for (int i = 0; i < m; ++i) hi[1][i] = 0;

  for (int i = 0; i < n; ++i) { 
    for (int j = 0; j < m; ++j) {
      scanf("%d", mp[i] + j);
      hi[0][i] = max(mp[i][j], hi[0][i]);
      hi[1][j] = max(mp[i][j], hi[1][j]);
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (hi[0][i] != mp[i][j] && hi[1][j] != mp[i][j]) {
	puts("NO");
	return;
      }
    }
  }
  
  puts("YES");
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t ; ++i) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
