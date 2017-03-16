#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}

char s[1000];
void rev(int k) {
  reverse(s, s + k);
  for (int i = 0; i < k; i++) {
    if (s[i] == '-') {
      s[i] = '+';
    } else {
      s[i] = '-';
    }
  }
}
void solve() {
  scanf("%s", s);
  int n = (int)strlen(s);
  int res = 0;
  while (1) {
    while (n > 0 && s[n - 1] == '+') {
      n--;
    }
    if (n == 0) break;
    int l = 0;
    while (l < n && s[l] == '+') {
      l++;
    }
    if (l > 0) {
      res++;
    }
    rev(l);
    rev(n);
    res++;
  }
  printf("%d\n", res);
}

int main(){
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  int T;
  scanf("%d", &T);
  for (int ti = 1; ti <= T; ti++) {
    printf("Case #%d: ", ti);
    solve();
  }
  return 0;
}
