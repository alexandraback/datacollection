#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int L = 1e6+10;

#define llg long long

int n,l;
char s[L];
int c[300] = {0},right[L];
bool ok[L];

inline llg solve () {
  scanf ("%s %d", s, &n);
  l = strlen (s);

  int cnt = 0;
  for (int i = 0;i < l;i ++) {
    if (c[s[i]] == 0) {
      cnt ++;
    } else {
      cnt = 0;
    }
    if (cnt >= n) {
      ok[i] = 1;
    } else {
      ok[i] = 0;
    }
  }

  int last = l;
  for (int i = l-1;i >= 0;i --) {
    if (ok[i]) {
      right[i] = last;
      last = i;
    }
  }

  llg ans = 0;
  for (int i = 0;i < l;i ++) {
    if (ok[i]) {
      ans += ((llg)i-n+2)*((llg)right[i]-i);
    }
  }
  return ans;
}

int main () {
  c['a'] = c['e'] = c['i'] = c['o'] = c['u'] = 1;

  int test;
  scanf ("%d", &test);

  for (int Case = 1;Case <= test;Case ++) {
    printf ("Case #%d: %lld\n", Case, solve ());
  }
}
