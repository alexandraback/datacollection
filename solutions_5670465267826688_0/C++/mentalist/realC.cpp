#include <stdio.h>

#define MAX 10005

int prefix[MAX], suffix[MAX];
char str[MAX];

int mmult[5][5] = {
  { 0, 0,  0,  0,  0 },
  { 0, 1,  2,  3,  4 },
  { 0, 2, -1,  4, -3 },
  { 0, 3, -4, -1,  2 },
  { 0, 4,  3, -2, -1 }
};

int mult(int a, int b) {
  int sign = 1;
  if(a < 0) { a = -a; sign *= -1; }
  if(b < 0) { b = -b; sign *= -1; }
  return sign*mmult[a][b];
}

int map(char c) {
  if(c == 'i') return 2;
  if(c == 'j') return 3;
  if(c == 'k') return 4;
  return -1;
}

void copy(int l, int cnt) {
  int idx = l;
  while(--cnt) {
    for(int i=0; i<l; ++i)
      str[idx++] = str[i];
  }
  str[idx] = '\0';
}

int main() {
  freopen("Creal.in", "r", stdin);
  freopen("Creal.out", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    int l, cnt, n;
    scanf("%d %d", &l, &cnt);
    scanf("%s", str);
    copy(l, cnt);
    n = l*cnt;
    for(int i=0; i<n; ++i) {
      if(i == 0) prefix[i] = map(str[i]);
      else prefix[i] = mult(prefix[i-1], map(str[i]));
    }
    for(int i=n-1; i>=0; --i) {
      if(i == n-1) suffix[i] = map(str[i]);
      else suffix[i] = mult(map(str[i]), suffix[i+1]);
    }
    int ok = 0;
    for(int i=1; i<n; ++i) {
      int mid = map(str[i]);
      for(int j=i+1; j<n; ++j) {
        int pre = prefix[i-1];
        int suf = suffix[j];
        if(pre == 2 && mid == 3 && suf == 4) {
          ok = 1;
          break;
        }
        mid = mult(mid, map(str[j]));
      }
      if(ok) break;
    }
    printf("Case #%d: %s\n", t, ok ? "YES" : "NO");
  }
  return 0;
}
    
