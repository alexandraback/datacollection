#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases) {
    printf("Case #%d: ", cases);
    scanf("%d%d%d", &n, &m, &k);
    if (n <= 2 || m <= 2 || k <= 4) {
      printf("%d\n", k);
      continue;
    }
    if (m * n - k <= 4) {
      printf("%d\n", m * 2 + n * 2 - 4 - (m * n - k));
      continue;
    }
    int ans = n * 2 + m * 2 - 4;
    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
	if ((i + j) * 2 < ans && (i * j + i * 2 + j * 2) >= k)
	  ans = i * 2 + j * 2;
    printf("%d\n", ans);
  }
  return 0;
}

