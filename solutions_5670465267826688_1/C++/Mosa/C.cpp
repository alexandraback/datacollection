#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

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
vals pref[N], suff[N];

vals eval(long long x) {
  vals v = ONE;
  vals base = ONE;
  for(int i = 0; foo[i]; ++i) {
    base = mat[base][get(foo[i])];
  }
  while(x > 0) {
    if(x & 1) {
      v = mat[v][base];
    }
    base = mat[base][base];
    x >>= 1;
  }
  return v;
}

int main() {
  freopen("C.in", "rt", stdin);
  freopen("C.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    int l;
    long long x;
    scanf("%d %lld", &l, &x);
    scanf("%s", foo);
    string s;
    while(x > 0 && (int)s.size() + l <= N) {
      s += foo;
      x--;
    }
    vals rest = eval(x);
    vals needI, needK;
    for(int i = 0; i < 8; ++i) {
      if(mat[i][rest] == I) {
        needI = (vals)i;
      }
      if(mat[i][rest] == K) {
        needK = (vals)i;
      }
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
      if(pref[i] == I && suff[i + 1] == needI) {
        left = i; break;
      }
    }
    for(int i = l - 1; i > 1; --i) {
      if(pref[i - 1] == K && suff[i] == needK) {
        right = i; break;
      }
    }
    printf("Case #%d: %s\n", test, (left < right) ? "YES" : "NO");
  }
  return 0;
}
