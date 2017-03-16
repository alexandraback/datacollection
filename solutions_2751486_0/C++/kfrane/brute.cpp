#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mxn = 1000000+5;
char niz[mxn];

inline bool kons(char zn) {
  if(zn == 'a' || zn == 'e' || zn == 'i' || zn == 'o' || zn == 'u') return 0;
  return 1;
}

int val(int i, int j) {
  int mx = 0, curr = 0;
  for(; i <= j; i++) {
    if (kons(niz[i])) curr++;
    else curr = 0;
    mx = max(mx, curr);
  }
  return mx;
}

void solve() {
  int n;

  scanf("%s", niz);
  scanf("%d", &n);

  int k = strlen(niz), ret = 0;
  for(int i = 0; i < k; i++) {
    for(int j = i; j < k; j++) {
      if (j-i+1 < n) continue;
      if(val(i,j) >= n) {
        ret++;
      }
    }
  }
  printf("%d\n", ret);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++) {
    printf("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
