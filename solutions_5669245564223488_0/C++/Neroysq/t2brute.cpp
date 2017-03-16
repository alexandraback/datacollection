#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int cmax = 26 + 18 + 'a', nmax = 100 + 18, lmax = 100 + 18, mo = 1000000000 + 7;

int n;
char word[nmax][lmax];
char current[nmax * lmax];
bool ed[nmax], edd[cmax];
int ans, tot;

void search(int i)
{
  if (i > n) {
    memset(edd, 0, sizeof(edd));
    for (int i = 1; i <= tot; ++i) {
      int c = current[i];
      if (edd[c]) return;
      while (i + 1 <= tot && current[i + 1] == c) ++i;
      edd[c] = 1;
    }
    ++ans;
    return;
  }
  for (int j = 1; j <= n; ++j)
    if (!ed[j]) {
      int tmp = tot;
      memcpy(current + tot + 1, word[j] + 1, strlen(word[j] + 1));
      tot += strlen(word[j] + 1);
      ed[j] = 1;
      search(i + 1);
      ed[j] = 0;
      tot = tmp;
    }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output2.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases) {
    printf("Case #%d: ", cases);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%s", word[i] + 1);
    ans = 0;
    search(1);
    printf("%d\n", ans);
  }
  return 0;
}

