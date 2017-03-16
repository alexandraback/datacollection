#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
char s[16][21], t[16][21];

int f(int k) {
  for (int i = 0; i < N; i++) {
    if (~k & 1 << i)
      continue;
    
    for (int j = 0; j < N; j++)
      if ((~k & 1 << j) && !strcmp(s[i], s[j]))
	goto end;
    return 0;
    end:;
    
    for (int j = 0; j < N; j++)
      if ((~k & 1 << j) && !strcmp(t[i], t[j]))
	goto end2;
    return 0;
    end2:;
  }
  int ret = 0;
  for (int i = 0; i < 16; i++)
    if (k & 1 << i)
      ret++;
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d", &N);
    int ans = 0;
    for (int j = 0; j < N; j++)
      scanf("%s%s", s[j], t[j]);
    for (int j = 1; j < (1 << N); j++)
      ans = max(ans, f(j));
    printf("Case #%d: %d\n", i, ans);
  }
}
