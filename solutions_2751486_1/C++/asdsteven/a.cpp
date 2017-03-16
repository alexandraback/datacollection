#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1000001];
int a[1000000];
bool b[128];

long long f() {
  int n, l;
  scanf("%s%d", s, &n);
  l = strlen(s);
  for (int i(0), j(0); i < l; i++) {
    if (b[s[i]])
      a[i] = j = 0;
    else
      a[i] = ++j;
  }
  long long ans(0);
  for (int i(0), j(n - 1); i < l; i++) {
    j = max(j, i + n - 1);
    while (j < l && a[j] < n)
      j++;
    if (j >= l)
      break;
    ans += l - j;
  }
  return ans;
}

int main() {
  b['a'] = b['e'] = b['i'] = b['o'] = b['u'] = true;
  int T;
  scanf("%d", &T);
  for (int i(1); i <= T; i++)
    printf("Case #%d: %lld\n", i, f());
}