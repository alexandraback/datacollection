#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[20], t[20];
long long d, ai, bi;

void f(int x, long long ui, long long vi) {
  if (!s[x]) {
    long long dd = max(ui, vi) - min(ui, vi);
    
    if (dd < d || (dd == d && ui < ai) || (dd == d && ui == ai && vi < bi))
      d = dd, ai = ui, bi = vi;
    return;
  }
  if (s[x] == '?' && t[x] == '?') {
    for (int i = 0; i <= 9; i++)
      for (int j = 0; j <= 9; j++)
	f(x + 1, ui * 10 + i, vi * 10 + j);
  } else if (s[x] == '?') {
      for (int j = 0; j <= 9; j++)
	f(x + 1, ui * 10 + j, vi * 10 + t[x] - '0');
    // if (t[x] != '0')
    //   f(x + 1, ui * 10 + t[x] - '1', vi * 10 + t[x] - '0');
    // f(x + 1, ui * 10 + t[x] - '0', vi * 10 + t[x] - '0');
    // if (t[x] != '9')
    //   f(x + 1, ui * 10 + t[x] - '0' + 1, vi * 10 + t[x] - '0');
  } else if (t[x] == '?') {
      for (int j = 0; j <= 9; j++)
	f(x + 1, ui * 10 + s[x] - '0', vi * 10 + j);
      // if (s[x] != '0')
    //   f(x + 1, ui * 10 + s[x] - '0', vi * 10 + s[x] - '1');
    // f(x + 1, ui * 10 + s[x] - '0', vi * 10 + s[x] - '0');
    // if (s[x] != '9')
    //   f(x + 1, ui * 10 + s[x] - '0', vi * 10 + s[x] - '0' + 1);
  } else {
    f(x + 1, ui * 10 + s[x] - '0', vi * 10 + t[x] - '0');
  }
}

void solve() {
  scanf("%s%s", s, t);
  d = (1ll << 63) - 1;
  f(0, 0, 0);
  for (int i = strlen(s) - 1; i >= 0; i--) {
    s[i] = ai % 10 + '0';
    t[i] = bi % 10 + '0';
    ai /= 10;
    bi /= 10;
  }
  printf("%s %s\n", s, t);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
