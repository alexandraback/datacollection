#include <bits/stdc++.h>

using namespace std;

enum vals {ONE, I, J, K, NONE, NI, NJ, NK};
vals mat[8][8] = {
    {ONE, I, J, K, NONE, NI, NJ, NK},
    {I, NONE, K, NJ, NI, ONE, NK, J},
    {J, NK, NONE, I, NJ, K, ONE, NI},
    {K, J, NI, NONE, NK, NJ, I, ONE},
    {NONE, NI, NJ, NK, ONE, I, J, K},
    {NI, ONE, NK, J, I, NONE, K, NJ},
    {NJ, K, ONE, NI, J, NK, NONE, I},
    {NK, NJ, I, ONE, K, J, NI, NONE}
};

vals get(char c) {
  if(c == 'i') return I;
  else if(c == 'j') return J;
  return K;
}

char foo[12345];
vals pref[12345], suff[12345];

int main() {
  freopen("C-small.in", "rt", stdin);
  freopen("C-small.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    int l, x; scanf("%d %d", &l, &x);
    scanf("%s", foo);
    string s;
    for(int i = 0; i < x; ++i) {
      s += foo;
    }
    l = s.size();
    pref[0] = get(s[0]);
    for(int i = 1; i < l; ++i) {
      pref[i] = mat[pref[i - 1]][get(s[i])];
    }
    suff[l - 1] = get(s[l - 1]);
    for(int i = l - 2; i >= 0; --i) {
      suff[i] = mat[get(s[i])][suff[i + 1]];
    }
    int left = l + 1, right = -1;
    for(int i = 0; i + 1 < l; ++i) {
      if(pref[i] == I && suff[i + 1] == I) {
        left = i; break;
      }
    }
    for(int i = l - 1; i > 1; --i) {
      if(pref[i - 1] == K && suff[i] == K) {
        right = i; break;
      }
    }
    printf("Case #%d: %s\n", test, (left < right) ? "YES" : "NO");
  }
  return 0;
}
