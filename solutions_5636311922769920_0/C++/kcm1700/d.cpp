#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++)
  {
    int K, C, S;
    scanf("%d%d%d", &K, &C, &S);
    if (C*S < K)
    {
      printf("Case #%d: IMPOSSIBLE\n", testcase);
      continue;
    }

    printf("Case #%d:", testcase);
    int ind = 0;
    for (int i = 0; i < S && ind < K; i++)
    {
      long long num = 0;
      for (int j = 0; j < C; j++)
      {
        num *= K;
        num += min(ind, K - 1);
        ind++;
      }
      num++;
      printf(" %lld", num);
    }
    puts("");
  }
  return 0;
}